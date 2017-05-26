#ifndef FIELD_H
#define FIELD_H

#include "commander.h"
#include "cardpool.h"

const unsigned row_number = 3;

class Field
{
    typedef std::vector<Card> Deck;
    public:
        Field();
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

        bool ally_passed = false;
        bool enemy_passed = false;

        unsigned round = 1;


//        methods
        unsigned strength(const int row) const;
        unsigned allyStrength() const;
        unsigned enemyStrength() const;

//        TODO : command


    private:
        bool correctPlacement(const Card& card, const int row) const;
        bool fromPoolToHand();
        bool fromHandToRow(const int row, const unsigned hand_position);
        bool fromEnemyToRow(const int row, const unsigned id);

};


#endif // FIELD_H
