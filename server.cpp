#include "server.h"
#include "proxy.h"

void Server::addClient(Proxy *c)
{
    clients.push_back(c);
}

void Server::sendClient(int clientId, int cardNo)
{
    if(clientId > clients.count())
        throw "incorrec client"; // TODO: add exception

    clients[clientId]->roundStart(cardNo);
}
