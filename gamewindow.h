#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "visualcomponent.h"

class GameWindow: public VisualComponent
{
public:
    explicit GameWindow(QWidget *parent = 0);
    GameWindow(const GameWindow &other) = delete;
    ~GameWindow() = default;

    void draw() override;

protected:
    void keyPressEvent(QKeyEvent *e) override;
};

#endif // GAMEWINDOW_H
