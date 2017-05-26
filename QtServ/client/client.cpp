#include "client.h"
#include "utils.hpp"
using namespace std;

Client::Client(int id, int cd, QObject* parent) :
    QObject(parent), player_id(id), card(cd)
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

void Client::start()
{
    QHostAddress addr(get_ip_addr());
    client.connectToHost(addr, get_port());
    cout << "Connecting to " << get_ip_addr() << ":" << get_port() << "..." << endl;
}

void Client::startTransfer()
{
    cout << "Connected!" << endl;

    QPair<int, int> request = {player_id, card};

    // Отправляем данные на сервер
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out << (quint16)0;
    out << request;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    client.write(block);

    cout << "Send to server: " << request.first << " " << request.second << endl;
}

void Client::readData()
{
    QPair<int, int> answer = {-2, -2};
    // Получаем ответ от сервера
    QDataStream in(&client);
    blockSize = 0;
    if (blockSize == 0) {
        if (client.bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }
    if (client.bytesAvailable() < blockSize)
        return;
    in >> answer;
    player_id = answer.first;
    card = answer.second;
    cout << "Answer from server: " << answer.first << " " << answer.second << endl;

    // Как только ответ от сервера получен выходим из приложения
    //qApp->exit();
}

// Обрабатываем возможные ошибки
void Client::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
            qApp->exit();
            break;
        case QAbstractSocket::HostNotFoundError:
            cout << "Error: Host not found" << endl;
            qApp->exit();
            break;
        case QAbstractSocket::ConnectionRefusedError:
            cout << "Error: Connection refused" << endl;
            qApp->exit();
            break;
        default:
            cout << "Error: " << client.errorString().toStdString() << endl;
            qApp->exit();
            break;
    }
}
