#ifndef FIELD_H
#define FIELD_H

#include "commander.h"
#include "cardpool.h"

const unsigned row_number = 3;

class Field
{
    typedef std::vector<Card> Deck;
    public:
        Field() = default;
        Field(const Field& other) = default;
        Field(Field& other) = default;

        virtual ~Field() = default;


//        data
        Deck ally_rows[row_number];
        Deck enemy_rows[row_number];

        CardPool pool;

        Commander enemy;
        Commander ally;

        Deck hand;
        unsigned enemy_hand = 10;


//        methods
        unsigned strength(const int row) const;
        unsigned allyStrength() const;
        unsigned enemyStrength() const;

        bool fromHandToRow(const unsigned hand_position, const int row);
        bool fromPoolToHand();

        bool fromEnemyToRow(const unsigned id, const int row);

    private:
        bool correctPlacement(const Card& card, const int row) const;

};


#endif // FIELD_H
