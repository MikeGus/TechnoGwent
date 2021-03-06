#include "testproxy.h"
#include "server.h"
#include "visual/visualscenebuilder.h"
#include "visual/visualscenedesigner.h"
#include "gamewindowsingle.h"

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

    GameWindowSingle::gameWindow() = win;

    Proxy::init(windowWidth, windowHeight);
}
