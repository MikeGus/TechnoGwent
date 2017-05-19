#include "proxy.h"
#include "server.h"

Proxy::Proxy(Server *s): serv(s)
{
}

void Proxy::init(int , int )
{
    if(serv)
        serv->addClient(this);
    else
        throw "No server found"; // TODO: add exception
}

void Proxy::roundStart(int)
{
}

void Proxy::roundEnd(int)
{

}
