#ifndef VIISUALCARDIDLESTATE_H
#define VIISUALCARDIDLESTATE_H

#include "visualcardstate.h"

class VisualCardIdleState : public VisualCardState
{
public:
    VisualCardIdleState(vcInfo *info, QPixmap *buffer);
    ~VisualCardIdleState() = default;

    void draw() override; // State-dependant draw
    void mouseEvent(QMouseEvent *ev) override; // State-dependant mouse event
};

#endif // VIISUALCARDIDLESTATE_H
