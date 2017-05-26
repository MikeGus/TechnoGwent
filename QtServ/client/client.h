#include <QApplication>
#include <QHostAddress>
#include <QtGui>
#include <QHash>
#include <iostream>
#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <string>

class Client: public QObject
{
    Q_OBJECT
public:
    Client(int id, int cd, QObject* parent = 0);
    ~Client();
    void start();
    int get_player_id();
    int get_card();

public slots:
    void startTransfer();
    void readData();

private slots:
    void displayErrorSlot(QAbstractSocket::SocketError);

private:
    QTcpSocket client;
    quint16 blockSize;
    int player_id = -1;
    int card = -1;
};
