#ifndef HAND_H
#define HAND_H

#include <vector>
#include <memory>

#include "card.h"
#include "commander.h"

class Hand
{
    public:
        void use_commander_ability(); //how to use?
        void add(std::shared_ptr<Card>& card);
        std::shared_ptr<Card> get(unsigned pos);

    private:
        std::vector<std::shared_ptr<Card>> deck;
        Commander commander;
};


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

#endif // HAND_H
