#ifndef TESTPROXY_H
#define TESTPROXY_H

#include "proxy.h"
#include "gamewindow.h"

class TestProxy : public Proxy
{
public:
    TestProxy();
    TestProxy(const TestProxy &other) = delete;
    ~TestProxy();

    void init(int windowWidth, int windowHeight) override;

private:
    GameWindow *win;
};

#endif // TESTPROXY_H
