#ifndef VISUALCARDFLOATINGSTATE_H
#define VISUALCARDFLOATINGSTATE_H

#include "visualcardstate.h"

class VisualCardFloatingState : public VisualCardState
{
public:
    VisualCardFloatingState(VisualCard *card, vcInfo *info, QPixmap *buffer);
    ~VisualCardFloatingState() = default;

    void mouseMoveEvent(QMouseEvent *ev) override; // State-dependant mouse events
    void mouseReleaseEvent(QMouseEvent *ev) override;

    void setShift(int shiftX, int shiftY);

private:
    int shiftX, shiftY; // Difference between left upper corner and a point,
                        // From which the card is being dragged
};

#endif // VISUALCARDFLOATINGSTATE_H
