#include "client.h"
#include "utils.h"

Client::Client(int id, int cd, int ln, QObject* parent) :
    QObject(parent), player_id(id), card(cd), line(ln)
{
  connect(&client, SIGNAL(connected()),
      this, SLOT(startTransfer()));
  connect(&client, SIGNAL(readyRead()),
      this, SLOT(readData()));
  connect(&client, SIGNAL(error(QAbstractSocket::SocketError)),
      this, SLOT(displayErrorSlot(QAbstractSocket::SocketError)));
}

Client::~Client()
{
    client.close();
}

int Client::get_player_id(){
    return player_id;
}

int Client::get_card(){
    return card;
}

int Client::get_line(){
    return line;
}

void Client::start()
{
    QHostAddress addr(get_ip_addr());
    client.connectToHost(addr, get_port());
    std::cout << "Info: Connecting to " << get_ip_addr() << ":" << get_port() << "..." << std::endl;
}

void Client::startTransfer()
{
    std::cout << "Info: Connected!" << std::endl;
    int_pair request = {player_id, {card, line}};

    // Send data to server
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << request;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    if (!client.write(block) == -1) {
        //std::err << "Error: Could not send request to server" << std::endl;
    }

    std::cout << "Info: Send to server: " << request.first << " " << request.second.first << " " << request.second.second << std::endl;
}

void Client::readData()
{
    int_pair answer = {-2, {-2,-2}};
    // Getting response from server
    QDataStream in(&client);
    blockSize = 0;
    if (blockSize == 0) {
        if (client.bytesAvailable() < (int)sizeof(quint16)) {
            std::string message = "Wrong message size from server";
            throw std::runtime_error(message);
        }
        in >> blockSize;
    }
    if (client.bytesAvailable() < blockSize) {
        std::string message = "Wrong message from server";
        throw std::runtime_error(message);
    }
    in >> answer;
    player_id = answer.first;
    card = answer.second.first;
    line = answer.second.second;
    std::cout << "Info: Answer from server: " << answer.first << " " << answer.second.first << " " << answer.second.second << std::endl;
    qApp->exit();
    return;
}

// Обрабатываем возможные ошибки
void Client::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            throw std::runtime_error("Host closed");
        case QAbstractSocket::HostNotFoundError:
            throw std::runtime_error("Host not found");
        case QAbstractSocket::ConnectionRefusedError:
            throw std::runtime_error("Connection Refused");
        default:
            std::cout << "Error: " << client.errorString().toStdString() << endl;
            qApp->exit();
            break;
    }
}
