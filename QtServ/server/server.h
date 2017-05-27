#include <QtNetwork>
#include <QApplication>
#include <iostream>
#include <string>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <random>
#include <ctime>


typedef QPair<int, QPair<int, int>> int_pair;

struct session{
    QPair<int, int> pair_id; // player1, player2
    bool whom_step_now; // someone, who play card now
    QPair<int, int>  last_step; // card id, row

    session(const QPair<int, int>& pair, const bool sp = true, const QPair<int, int>& ls = {-1, -1});
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
    const int find_index(const int&) const;
    const int_pair get_message();
    bool send_response(const int_pair&) const;

    QTcpServer server;
    QTcpSocket* client;
    quint16 blockSize;

    QVector<session> session_pool; //session pool
    int last_id;
};
