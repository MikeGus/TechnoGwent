#include "visualcardidlestate.h"

VisualCardIdleState::VisualCardIdleState(vcInfo *_info, QPixmap *_buffer): VisualCardState(_info, _buffer)
{
}

void VisualCardIdleState::draw()
{
    // Nothing else to be drawn in idle state
    // TODO: add hover highlight
}

void VisualCardIdleState::mouseEvent(QMouseEvent *)
{
    // TODO: have to handle state change: either highlight when hoverd or go to floating state
}
