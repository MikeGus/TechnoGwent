#ifndef FIELD_H
#define FIELD_H

#include "commander.h"
#include "cardpool.h"

const unsigned row_number = 3;

class Field
{
    typedef std::vector<Card> Deck;
    public:
        Deck ally_rows[row_number];
        Deck enemy_rows[row_number];

        CardPool pool;

        Deck hand;

        Commander enemy;
        Commander ally;

        unsigned strength(int row) const;
        unsigned allyStrength() const;
        unsigned enemyStrength() const;

        bool fromHandToRow(unsigned hand_position, int row);

};


#endif // FIELD_H
