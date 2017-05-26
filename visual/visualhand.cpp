#include <stdexcept>
#include <QPainter>
#include "visualhand.h"

VisualHand::VisualHand(QWidget *parent): VisualComponent(parent), horizontalLayout(new QHBoxLayout)
{
    setLayout(horizontalLayout);
}

VisualHand::VisualHand(const VisualHand &other): VisualComponent(other)
{
}

void VisualHand::insertCard(const std::shared_ptr<VisualCard> &card, int id)
{

    if(id >= cards.size())
    {
        cards.push_back(card);
        horizontalLayout->addWidget(card.get());
    }
    else
    {
        cards.insert(id, card);
        horizontalLayout->insertWidget(id, card.get());
    }
}

void VisualHand::removeCard(int id) throw(std::out_of_range)
{
    if(id >= cards.size())
        throw std::out_of_range("Removing non-existing card from hand");

    horizontalLayout->removeWidget(cards[id].get());
    cards.remove(id);
}

void VisualHand::draw()
{
    QPainter p(buffer);
    p.setPen(Qt::red);

    p.drawRoundedRect(30, 10, width()-60, height()-20, 10, 10);

    p.end();
}
