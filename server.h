#ifndef SERVER_H
#define SERVER_H

#include <QVector>

class Proxy;

class Server
{
public:
    Server() = default;
    Server(const Server &other) = delete;
    virtual ~Server() = default;

    virtual void addClient(Proxy *c);
    virtual void sendClient(int clientId, int cardNo);

protected:
    QVector<Proxy *> clients;

};

#endif // SERVER_H
