#include <QLayout>
#include <stdexcept>
#include "visualscenedesigner.h"

VisualSceneDesigner::VisualSceneDesigner(VisualSceneBuilder *_builder):
    builder(_builder != nullptr ? _builder : throw std::invalid_argument("No builder specified"))
{
}

VisualSceneDesigner::~VisualSceneDesigner()
{
    delete builder;
}

GameWindow *VisualSceneDesigner::getWindow(int width, int height)
{
    if(!builder)
        throw std::invalid_argument("No builder specified!");

    GameWindow *win = new GameWindow;
    win->resize(width, height);
    QHBoxLayout *hor = new QHBoxLayout;
    QVBoxLayout *ver = new QVBoxLayout;


    for(int j = 0; j < 4; j++)
    {
        VisualRow *row = builder->buildRow();
        QHBoxLayout *rowHor = new QHBoxLayout;

        for(int i = 0; i < 6; i++)
        {
            VisualCard *vc = new VisualCard;
            rowHor->addWidget(vc);
            row->setLayout(rowHor);
        }

        ver->addWidget(row);
    }

    VisualNullRow *null = builder->buildNullRow();
    ver->addWidget(null);

    for(int j = 0; j < 4; j++)
    {
        VisualRow *row = builder->buildRow();
        QHBoxLayout *rowHor = new QHBoxLayout;

        for(int i = 0; i < 6; i++)
        {
            VisualCard *vc = new VisualCard;
            rowHor->addWidget(vc);
            row->setLayout(rowHor);
        }

        ver->addWidget(row);
    }

    hor->addLayout(ver);
    win->setLayout(hor);

    VisualMessage *msg = new VisualMessage(win, "Some text");
    msg->resize(win->width(), win->height()/4);
    msg->move(0, win->height()/2 - win->height()/8);

    return win;
}
