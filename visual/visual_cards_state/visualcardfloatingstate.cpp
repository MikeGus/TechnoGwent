#include "visualcardfloatingstate.h"
#include "../visualcard.h"

VisualCardFloatingState::VisualCardFloatingState(VisualCard *card, vcInfo *info, QPixmap *buffer):
    VisualCardState(card, info, buffer)
{
}

void VisualCardFloatingState::mouseMoveEvent(QMouseEvent *ev)
{
    if(possessor)
    {
        int realx = ev->x() - shiftX;
        int realy = ev->y() - shiftY;

        possessor->move(realx, realy);
        possessor->repaint(); // Maybe not needed
    }
}

void VisualCardFloatingState::mouseReleaseEvent(QMouseEvent *)
{
    // TODO: dropping check;
}

void VisualCardFloatingState::setShift(int _shiftX, int _shiftY)
{
    shiftX = _shiftX;
    shiftY = _shiftY;
}
