#ifndef FIELD_H
#define FIELD_H

#include "side.h"
#include "hand.h"
#include <ctime>
#include <random>

struct Field
{
    public:
        Field();

        Side allied_forces;
        Side enemy_forces;

        Commander enemy_commander;

        Hand hand;

        // need special class pool
        std::vector<std::shared_ptr<Card>> drop;
        std::vector<std::shared_ptr<Card>> pool;

        //methods
        bool from_hand_to_side(unsigned pos, int row);
        void rand_from_pool();
};


#endif // FIELD_H
