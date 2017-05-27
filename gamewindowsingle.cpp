#include "gamewindowsingle.h"

GameWindow *&GameWindowSingle::gameWindow()
{
    static GameWindow *win = nullptr;

    return win;
}
