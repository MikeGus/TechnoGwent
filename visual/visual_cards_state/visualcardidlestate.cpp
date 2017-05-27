#include <QLayout>
#include "visualcardidlestate.h"
#include "visualcardfloatingstate.h"
#include "../visualcard.h"

VisualCardIdleState::VisualCardIdleState(VisualCard *card, vcInfo *_info, QPixmap *_buffer):
    VisualCardState(card, _info, _buffer)
{
}

void VisualCardIdleState::mouseMoveEvent(QMouseEvent *)
{
    // Don't do anything yet;
    // TODO: maybe add hover reaction
}

void VisualCardIdleState::mousePressEvent(QMouseEvent *ev)
{
    VisualCardFloatingState *floatingState = new VisualCardFloatingState(possessor, info, buffer);
    floatingState->setShift(ev->x() - possessor->x(), ev->y() - possessor->y());

    // Remove itself from layout
    possessor->parentWidget()->layout()->removeWidget(possessor);

    possessor->changeState(floatingState);
}
