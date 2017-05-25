#ifndef FIELD_H
#define FIELD_H

#include "commander.h"
#include "cardpool.h"

const unsigned row_number = 6;

class Field
{
    typedef std::vector<Card> Deck;
    public:
        Deck rows[row_number];

        CardPool pool;

        Deck hand;

        Commander enemy;
        Commander ally;

        unsigned strength(unsigned row) const;
        unsigned allyStrength() const;
        unsigned enemyStrength() const;

};


#endif // FIELD_H
