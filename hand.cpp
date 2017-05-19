#include "hand.h"

void Hand::add(std::shared_ptr<Card>& card)
{
    deck.push_back(card);
}


std::shared_ptr<Card> Hand::get(unsigned pos)
{
    auto position = deck.begin() + pos;
    std::shared_ptr<Card> result(*position);

    deck.erase(position);

    return result;
}

bool Hand::move_availible()
{
    return (deck.size() != 0) || (!commander.ability_used());
}
