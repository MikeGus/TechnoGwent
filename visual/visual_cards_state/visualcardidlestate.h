#ifndef VIISUALCARDIDLESTATE_H
#define VIISUALCARDIDLESTATE_H

#include "visualcardstate.h"

class VisualCardIdleState : public VisualCardState
{
public:
    VisualCardIdleState(VisualCard *card, vcInfo *info, QPixmap *buffer);
    ~VisualCardIdleState() = default;

    void mouseMoveEvent(QMouseEvent *ev) override; // State-dependant mouse events
    void mousePressEvent(QMouseEvent *ev) override;
};

#endif // VIISUALCARDIDLESTATE_H
