#include <QKeyEvent>
#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent): VisualComponent(parent)
{
}

void GameWindow::draw()
{
    VisualComponent::draw();
}

void GameWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
        close();

    QWidget::keyPressEvent(e);
}
