#ifndef PROXY_H
#define PROXY_H

class Server;

class Proxy
{
public:
    Proxy(Server *s);
    Proxy(const Proxy &other) = delete;
    virtual ~Proxy() = default;

    virtual void init(int windowWidth, int windowHeight);
    virtual void roundStart(int cardNo);
    virtual void roundEnd(int cardNo);

protected:
    Server *serv;
};

#endif // PROXY_H
