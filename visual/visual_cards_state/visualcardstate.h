#ifndef VISUALCARDSTATE_H
#define VISUALCARDSTATE_H

#include <QMouseEvent>
#include "../visualcardinfo.h"

class VisualCardState
{
public:
    VisualCardState(const vcInfo *info);
    ~VisualCardState() = default;

    virtual void draw() = 0; // State-dependant draw
    virtual void mouseEvent(QMouseEvent *ev) = 0; // State-dependant mouse event

protected:
    vcInfo *info;
};

#endif // VISUALCARDSTATE_H
