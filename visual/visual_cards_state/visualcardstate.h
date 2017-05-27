#ifndef VISUALCARDSTATE_H
#define VISUALCARDSTATE_H

#include <QMouseEvent>
#include "../visualcardinfo.h"

class VisualCard;

class VisualCardState
{
public:
    VisualCardState(VisualCard *card, vcInfo *info, QPixmap *buffer);
    ~VisualCardState() = default;

    virtual void draw(); // State-dependant draw
    virtual void mouseMoveEvent(QMouseEvent *ev); // State-dependant mouse events
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);

protected:
    VisualCard *possessor;
    vcInfo *info;
    QPixmap *buffer;
};

#endif // VISUALCARDSTATE_H
