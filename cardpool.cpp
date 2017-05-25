#include "cardpool.h"

CardPool::CardPool(size_t _size, int _mixKey)
{
    generate(_size);
    mixCards(_mixKey);
}

Card CardPool::getCard()
{
    Card c(availible.back());
    availible.pop_back();
    return c;
}

void CardPool::returnDead(const Card &deadCard)
{
    dead.push_back(deadCard);
}

void CardPool::mixCards(int )
{
}

void CardPool::generate(size_t size)
{
    for(size_t i = 0; i < size; i++)
        availible.push_back(Card(i));
}

bool CardPool::emptyAvailible() const
{
    return availible.empty();
}

bool CardPool::emptyDead() const
{
    return dead.empty();
}
