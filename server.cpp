#include <stdexcept>
#include "server.h"
#include "proxy.h"

void Server::addClient(Proxy *c)
{
    clients.push_back(c);
}

void Server::sendClient(int clientId, int cardNo)
{
    if(clientId > clients.count())
        throw std::invalid_argument("Incorrect client given");

    clients[clientId]->roundStart(cardNo);
}
