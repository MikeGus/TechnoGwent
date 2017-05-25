#include <QPainter>
#include "visualmessage.h"

VisualMessage::VisualMessage(QWidget *parent, QString _text, QColor _bgColor, QColor _textColor): VisualComponent(parent),
    text(_text), bgColor(_bgColor), textColor(_textColor)
{
}

void VisualMessage::draw()
{
    buffer->fill(bgColor);
    QPainter p(buffer);

    p.setPen(textColor);
    p.drawText(width()/2, height()/2, text);

    p.end();
}


