#include <QtNetwork>
#include <QApplication>
#include <iostream>
#include <string>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <random>
#include <ctime>

typedef QPair<int, int> int_pair;

struct session{
    int_pair pair_id;
    bool whom_step_now; // someone, who play card now
    int last_step; // card id

    session(const int_pair& pair, const bool sp = true, const int ls = -1);
    session();
};


class Server: public QObject
{
  Q_OBJECT
  public:
    Server(QObject* parent = 0);
    ~Server();

  public slots:
    void acceptConnection();
    void startRead();

  private:
    const int_pair response_manager(const int_pair&);
    const int find_index(const int&);
    const int_pair get_message();
    bool send_response(const int_pair&);

    QTcpServer server;
    QTcpSocket* client;
    quint16 blockSize;

    QVector<session> session_pool; //session pool
    int last_id;
};
