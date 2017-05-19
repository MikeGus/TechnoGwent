#ifndef FIELD_H
#define FIELD_H

#include "side.h"
#include "hand.h"
#include <ctime>
#include <random>

struct Field
{
    public:
        Side allied_forces;
        Side enemy_forces;

        Commander enemy_commander;

        Hand hand;

        std::vector<std::shared_ptr<Card>> drop;
        std::vector<std::shared_ptr<Card>> deck;

        bool from_hand_to_side(unsigned pos, int row);
        void rand_from_deck();
};


#endif // FIELD_H
