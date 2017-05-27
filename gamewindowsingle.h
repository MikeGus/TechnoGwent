#ifndef GAMEWINDOWSINGLE_H
#define GAMEWINDOWSINGLE_H

#include "gamewindow.h"

class GameWindowSingle
{
public:
    GameWindowSingle() = delete;
    ~GameWindowSingle() = delete;

    static GameWindow *&gameWindow();
};

#endif // GAMEWINDOWSINGLE_H
