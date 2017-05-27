#include <QPainter>
#include "visualcard.h"
#include "visual_cards_state/visualcardidlestate.h"

VisualCard::VisualCard(QWidget *parent, const std::shared_ptr<Card> &_card,
                       QString _description, QString textureFile, bool _bFaceUp): VisualComponent(parent),
    info(new vcInfo(_card, _description, textureFile == "" ? nullptr : new QPixmap(textureFile))),
    curState(new VisualCardIdleState(this, info, buffer)), bFaceUp(_bFaceUp)
{
    setMouseTracking(true);
}

VisualCard::~VisualCard()
{
    if(info)
        delete info;
}

void VisualCard::setFaceUp(bool bUp)
{
    bFaceUp = bUp;
}

bool VisualCard::isFaceUp()
{
    return bFaceUp;
}

void VisualCard::changeState(VisualCardState *newState)
{
    if(curState)
        delete curState;

    curState = newState;
}

void VisualCard::draw()
{
    if(curState)
        curState->draw();
}

void VisualCard::drawBasic()
{
    QPainter p(buffer);
    p.setPen(Qt::green);

    if(info->texture)
        p.drawPixmap(0,0, info->texture->width(), info->texture->height(), *info->texture);

    p.drawRoundedRect(10, 10, width() - 20, height() - 20, 10, 10);

    p.setPen(Qt::darkGreen);
    if(bFaceUp)
        p.drawText(width()/4, height()/2, info->description);
    else
        p.drawText(width()/4, height()/2, "Back side");

    p.end();
}

void VisualCard::resizeEvent(QResizeEvent *re)
{
    VisualComponent::resizeEvent(re);

    setFixedWidth(height()*.8);
}

void VisualCard::mousePressEvent(QMouseEvent *ev)
{
    if(curState)
        curState->mousePressEvent(ev);
}

void VisualCard::mouseMoveEvent(QMouseEvent *ev)
{
    if(curState)
        curState->mouseMoveEvent(ev);
}

void VisualCard::mouseReleaseEvent(QMouseEvent *ev)
{
    if(curState)
        curState->mouseReleaseEvent(ev);
}
