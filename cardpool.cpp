#include "cardpool.h"

CardPool::CardPool(size_t _size, int _mixKey)
{
    generate(_size);
    mixCards(_mixKey);
}

Card CardPool::getCard()
{
    Card c(available.back());
    available.pop_back();
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
        available.push_back(Card(i));
}
