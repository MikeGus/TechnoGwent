#include "visualscenebuilder.h"

VisualRow *VisualSceneBuilder::buildRow(QWidget *parent)
{
    return new VisualRow(parent);
}

VisualMessage *VisualSceneBuilder::buildMessage(QWidget *parent, QString text,
                                                QColor bgColor, QColor textColor)
{
    return new VisualMessage(parent, text, bgColor, textColor);
}

VisualNullRow *VisualSceneBuilder::buildNullRow(QWidget *parent)
{
    return new VisualNullRow(parent);
}

VisualCard *VisualSceneBuilder::buildVisualCard(QWidget *parent, const std::shared_ptr<Card> &card,
                                                QString description, QString textureFile)
{
    return new VisualCard(parent, card, description, textureFile);
}

VisualHand *VisualSceneBuilder::buildVisualHand(QWidget *parent)
{
    return new VisualHand(parent);
}
