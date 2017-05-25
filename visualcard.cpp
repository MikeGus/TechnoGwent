#include <QPainter>
#include "visualcard.h"

VisualCard::VisualCard(QWidget *parent, const std::shared_ptr<Card> &_card, QString _description, QString textureFile): VisualComponent(parent),
    card(_card), description(_description), texture( textureFile == "" ? nullptr : new QPixmap(textureFile))
{
}

void VisualCard::draw()
{
    QPainter p(buffer);
    p.setPen(Qt::green);

    if(texture)
        p.drawPixmap(0,0, texture->width(), texture->height(), *texture);

    p.drawRoundedRect(10, 10, width() - 20, height() - 20, 10, 10);

    p.setPen(Qt::darkGreen);
    p.drawText(width()/4, height()/2, description);

    p.end();
}

void VisualCard::resizeEvent(QResizeEvent *re)
{
    VisualComponent::resizeEvent(re);

    setFixedWidth(height()*.8);
}
