#include "server.h"
#include "utils.h"
#define SESSION_AMOUNT (100)

session::session(const QPair<int,int>& pair, const bool sp, const QPair<int,int>& ls)
    : pair_id(pair), whom_step_now(sp), last_step(ls)
{
}


session::session()
{
}

Server::Server(QObject* parent)
    : QObject(parent),
    last_id(-1)
{
    connect(&server, SIGNAL(newConnection()),
        this, SLOT(acceptConnection()));
    // Run server
    if(server.listen(QHostAddress::Any, get_port())){
        std::cout << "Info: Server started" << std::endl;
    }
    else{
        std::cerr << "Error: Server not started" << std::endl;
        std::string message = "Couldn't start server with port" + get_port();
        throw std::domain_error(message);
    }
}

Server::~Server()
{
    server.close();
}

void Server::acceptConnection()
{
    client = server.nextPendingConnection();
    if (!client) {
        std::cerr << "Warning: Wrong client connection" << std::endl;
        client->close();
        return;
    }
    connect(client, SIGNAL(readyRead()),
        this, SLOT(startRead()));
}

const int_pair Server::get_message() {
    QDataStream in(client);
    blockSize = 0;
    if (blockSize == 0) {
        if (client->bytesAvailable() < (int)sizeof(quint16)) {
            client->close();
            std::string message = "Warning: Wrong message size";
            throw std::runtime_error(message);
        }
        in >> blockSize;
    }
    if (client->bytesAvailable() < blockSize) {
        client->close();
        std::string message = "Warning: Wrong message";
        throw std::runtime_error(message);
    }
    int_pair message;
    in >> message;
    return message;
}

bool Server::send_response(const int_pair& response) const {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << response;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    return (client->write(block) == -1);
}

void Server::startRead() {
    int_pair message;
    try {
        message = get_message();
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        client->close();
        return;
    }

    int_pair response = response_manager(message);
    //std::cout << "Info: Send to client: " << client->localAddress().toString() << " " << response.first << " " << response.second << std::endl;
    if (send_response(response)) {
        std::cerr << "Error: Couldn't send response to " << response.first;
    }
    client->close();
}

const int Server::find_index(const int& player_id) const {
    for(int index = 0; index < session_pool.size(); ++index) {
        if(session_pool[index].pair_id.first == player_id ||
                session_pool[index].pair_id.second == player_id){
            return index;
        }
    }
    return -1;
}

const int_pair Server::response_manager(const int_pair& message) {
    int_pair response = message;
    int player_id = message.first, card = message.second.first, line = message.second.second;
    // Checking request time and valid args amount
    if (player_id == -1 && card == -1 && line == -1){ // registration
        if (session_pool.size() > SESSION_AMOUNT){ // remove first ten session, if session amount more than 100;
            session_pool.remove(0, 10);
        }
        last_id++;
        if (last_id > SESSION_AMOUNT && (!last_id%2)) { // reset id counter only if this id is even, because using last_id - 1 for pair session later
            last_id = last_id % SESSION_AMOUNT;
        }
        if (last_id % 2) {
            QPair<int,int> opponents = {last_id, last_id - 1};
            session sess(opponents);
            session_pool.append(sess);
        }
        response.first = last_id;
        srand(time(0));
        response.second.first = rand();
        response.second.second = -1;
    }
    else if (player_id != -1 && card == -1 && line == -1) { // waiting opponent step
        int index = find_index(player_id);
        if (index >= 0 && session_pool[index].whom_step_now == player_id % 2) { // step is done (when requester step)
            response.second = session_pool[index].last_step;
        }
    }
    else if (player_id != -1 && card != -1 && line != -1) { // step with checking, if his step
        int index = find_index(player_id);
        if (index >= 0 && session_pool[index].whom_step_now == player_id % 2){
            session_pool[index].whom_step_now = !session_pool[index].whom_step_now;
            session_pool[index].last_step = message.second;
            response.second.first = -1;
            response.second.second = -1;
        }
    }
    else if (player_id != -1 && card == -2 && line == -2) { // close session with removing
        int index = find_index(player_id);
        if (index > 0 && session_pool[index].whom_step_now == player_id % 2) {
            session_pool.remove(index, 1);
            response.first = -1;
        }
    }
    return response;
}
