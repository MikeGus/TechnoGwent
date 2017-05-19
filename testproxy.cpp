#include "testproxy.h"
#include "server.h"
#include "visualscenebuilder.h"
#include "visualscenedesigner.h"

TestProxy::TestProxy(): Proxy(new Server), win(nullptr)
{
}

TestProxy::~TestProxy()
{
    if(serv)
        delete serv;
    if(win)
        delete win;
}

void TestProxy::init(int windowWidth, int windowHeight)
{
    VisualSceneBuilder build;
    VisualSceneDesigner des(&build);
    win = des.getWindow(windowWidth, windowHeight);
    win->showFullScreen();

    Proxy::init(windowWidth, windowHeight);
}
