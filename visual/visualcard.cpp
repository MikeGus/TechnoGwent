#include <QPainter>
#include "visualcard.h"

VisualCard::VisualCard(QWidget *parent, const std::shared_ptr<Card> &_card,
                       QString _description, QString textureFile): VisualComponent(parent),
    info(new vcInfo(_card, _description, textureFile == "" ? nullptr : new QPixmap(textureFile)))
{
}

VisualCard::VisualCard(const VisualCard &other): VisualComponent(other)
{
    if(info)
        delete info;

    info = new vcInfo(other.info->card, other.info->description, new QPixmap(*other.info->texture));
}

VisualCard::~VisualCard()
{
    if(info)
        delete info;
}

void VisualCard::draw()
{
    QPainter p(buffer);
    p.setPen(Qt::green);

    if(info->texture)
        p.drawPixmap(0,0, info->texture->width(), info->texture->height(), *info->texture);

    p.drawRoundedRect(10, 10, width() - 20, height() - 20, 10, 10);

    p.setPen(Qt::darkGreen);
    p.drawText(width()/4, height()/2, info->description);

    p.end();
}

void VisualCard::resizeEvent(QResizeEvent *re)
{
    VisualComponent::resizeEvent(re);

    setFixedWidth(height()*.8);
}
