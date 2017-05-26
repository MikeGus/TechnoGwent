#include "server.h"
#include "utils.hpp"

session::session(const int_pair& pair, const bool sp, const int ls)
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
    // Запускаем сервер
    if(server.listen(QHostAddress::Any, get_port())){
        std::cout << "Server started" << endl;
    }
    else{
        std::cerr << "Server not started" << endl;
        std::string message = "Couldn't start server with port" + port;
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
    connect(client, SIGNAL(readyRead()),
        this, SLOT(startRead()));
}

const int_pair Server::get_message() {
    QDataStream in(client);
    blockSize = 0;
    if (blockSize == 0) {
        if (client->bytesAvailable() < (int)sizeof(quint16))
            client->close();
            std::string message = "Wrong message size from " + client->localAddress() +
                    ":" + client->localPort() + std::endl;
            throw std::runtime_error(message);
        in >> blockSize;
    }
    if (client->bytesAvailable() < blockSize)
        client->close();
        std::string message = "Wrong message from " + client->localAddress() +
                ":" + client->localPort() + std::endl;
        throw std::runtime_error(message);

    QPair<int, int> message;
    in >> message;
    return message;
}

bool Server::send_response(const int_pair& response) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << response;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    return (client->write(block) == -1);
}

void Server::startRead()
{
    try {
        int_pair message = get_message();
    }
    catch (std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        client->close();
        return;
    }

    QPair<int, int> response = response_manager(message);

    std::cout << "Send to client: " << response.first << " " << response.second << std::endl;

    if (send_response(response)) {
        std::cerr << "Couldn't send response to " << response.first << " on address "
                  << client->localAddress() << ":" << client->localPort() << std::endl;
    }

    client->close();
}

const int Server::find_index(const int& player_id) {
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
    int player_id = message.first, card = message.second;
    // Проверяем тип запроса и количество аргументов
    if (player_id == -1 && card == -1){ //регистрация
        last_id++;
        if (last_id % 2){
            QPair<int, int> opponents = {last_id, last_id -1};
            session sess(opponents);
            session_pool.append(sess);
        }
        response.first = last_id;
        srand(time(0));
        response.second = rand();
    }
    else if (player_id != -1 && card == -1) { // в ожидании хода соперника
        int index = find_index(card);
        if (index > 0 && session_pool[index].whom_step_now == player_id % 2) { // ход совершен
            response.second = session_pool[index].last_step;
        }
    }
    else if (player_id != -1 && card != -1) { //ход, проверить имеет ли право
        int index = find_index(card);
        if (index > 0 && session_pool[index].whom_step_now == player_id % 2){
            session_pool[index].whom_step_now = !session_pool[index].whom_step_now;
            session_pool[index].last_step = card;
            response.second = -1;
        }
    }
    else if (player_id != -1 && card == -2) {
        int index = find_index(card);

    }
    return response;
}
