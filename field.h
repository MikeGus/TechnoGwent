#ifndef FIELD_H
#define FIELD_H

#include "commander.h"
#include "desk.h"

const unsigned number_of_rounds = 3;

class Field
{
    typedef std::vector<Card> Deck;
    public:
        Field(const unsigned mixKey = 0, const unsigned commander_id = 0, const unsigned enemy_commander_id = 1);
        Field(const Field& other) = default;
        Field(Field& other) = default;

        virtual ~Field() = default;


//        data
        Desk desk;

        Commander ally;
        Commander enemy;

        Deck hand;
        unsigned enemy_hand = 10;

        bool ally_passed = false;
        bool enemy_passed = false;

        unsigned round = 1;
        unsigned round_won = 0;
        unsigned round_lost = 0;


//        methods
        unsigned strength(const int row) const;
        unsigned allyStrength() const;
        unsigned enemyStrength() const;

        void pass();
        bool fromHandToRow(const int row, const unsigned hand_position);
        bool fromEnemyToRow(const int row, const unsigned id);

        void initialize(const unsigned seed);

        bool nextRound();
        int roundWinner();

        bool finishGame();

//        TODO : command


    private:
        bool correctPlacement(const Card& card, const int row) const;
        bool fromPoolToHand();


};


#endif // FIELD_H
