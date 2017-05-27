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
    VisualNullRow *battleFieldContainer = builder->buildNullRow(win);
    QHBoxLayout *hor = new QHBoxLayout;
    QVBoxLayout *ver = new QVBoxLayout;


    VisualHand *opponentHand = builder->buildVisualHand();
    ver->addWidget(opponentHand);
    for(int i = 0; i < 8; i++)
    {
        VisualCard *vc = builder->buildVisualCard();
        vc->setFaceUp(false);
        std::shared_ptr<VisualCard> vcShared(vc);
        opponentHand->insertCard(vcShared, i);
    }

    for(int j = 0; j < 3; j++)
    {
        VisualRow *row = builder->buildRow();
        QHBoxLayout *rowHor = new QHBoxLayout;

        for(int i = 0; i < 6; i++)
        {
            VisualCard *vc = builder->buildVisualCard();
            rowHor->addWidget(vc);
            row->setLayout(rowHor);
        }

        ver->addWidget(row);
    }

    VisualNullRow *null = builder->buildNullRow();
    ver->addWidget(null);

    for(int j = 0; j < 3; j++)
    {
        VisualRow *row = builder->buildRow();
        QHBoxLayout *rowHor = new QHBoxLayout;

        for(int i = 0; i < 6; i++)
        {
            VisualCard *vc = builder->buildVisualCard();
            rowHor->addWidget(vc);
            row->setLayout(rowHor);
        }

        ver->addWidget(row);
    }

    VisualHand *vhand = builder->buildVisualHand();

    for(int i = 0; i < 10; i++)
        vhand->insertCard(std::shared_ptr<VisualCard>(builder->buildVisualCard()), i);
    ver->addWidget(vhand);

    battleFieldContainer->setLayout(ver);
    hor->addWidget(battleFieldContainer);
    win->setLayout(hor);

    // Really tired of this message
    // TODO: fade-in/fade-out
    //VisualMessage *msg = new VisualMessage(win, "Some text");
    //msg->resize(win->width(), win->height()/6);
    //msg->move(0, win->height()/2 - win->height()/8);

    return win;
}
