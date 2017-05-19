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

        bool move_availible();

    private:
        std::vector<std::shared_ptr<Card>> deck;
        Commander commander;
};


#endif // HAND_H
