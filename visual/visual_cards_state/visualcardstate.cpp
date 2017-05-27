#include "visualcardstate.h"
#include "../visualcard.h"

VisualCardState::VisualCardState(VisualCard *card, vcInfo *_info, QPixmap *_buffer):
    possessor(card), info(_info), buffer(_buffer)
{
}

void VisualCardState::draw()
{
    if(possessor)
        possessor->drawBasic();
}

void VisualCardState::mouseMoveEvent(QMouseEvent *)
{
}

void VisualCardState::mousePressEvent(QMouseEvent *)
{
}

void VisualCardState::mouseReleaseEvent(QMouseEvent *)
{
}
