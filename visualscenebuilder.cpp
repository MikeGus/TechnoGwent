#include "visualscenebuilder.h"

VisualRow *VisualSceneBuilder::buildRow(QWidget *parent)
{
    return new VisualRow(parent);
}

VisualMessage *VisualSceneBuilder::buildMessage(QWidget *parent, QString _text, QColor _bgColor, QColor _textColor)
{
    return new VisualMessage(parent, _text, _bgColor, _textColor);
}

VisualNullRow *VisualSceneBuilder::buildNullRow(QWidget *parent)
{
    return new VisualNullRow(parent);
}
