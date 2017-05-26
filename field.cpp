#include "field.h"

Field::Field() : enemy_hand(10), ally_passed(false), enemy_passed(true), round(1)
{
//    TODO: fill pool from db
    for (unsigned i = 0; i < 10; ++i) {
        fromPoolToHand();
    }
}



unsigned Field::strength(const int row) const
{
    if ((static_cast<unsigned>(abs(row)) >= row_number) || (row == 0)) {
        throw(std::logic_error("Wrong row number!"));
    }

    unsigned str = 0;
    unsigned count = 0;

    unsigned golden = 0;

    unsigned modificator = 1;
    bool zero_modificator = false;

//    check every card in a row
    const Deck* rows(ally_rows);
    if (row < 0) {
        rows = enemy_rows;
    }

    for (const Card& card : rows[row]) {
        if (card.role() == Role::fighter || card.role() == Role::maniac) {
            if (card.golden()) {
                golden += card.value();
            }
            else {
                str += card.value();
                ++count;
            }
        }
        else if (card.role() == Role::modificator) {
            if (card.value() == 0) {
                zero_modificator = true;
            }
            else {
                modificator *= card.value();
            }
        }
    }

    unsigned result = str;

    if (zero_modificator) {
        result = count;
    }

    result *= modificator;
    result += golden;

    return result;
}

unsigned Field::allyStrength() const
{
    unsigned str = 0;
    for (unsigned i = 0; i < row_number; ++i) {
        str += strength(i);
    }
    return str;
}


unsigned Field::enemyStrength() const
{
    unsigned str = 0;
    for (unsigned i = 1 - row_number; i < 1; ++i) {
        str += strength(i);
    }
    return str;
}

bool Field::correctPlacement(const Card& card, const int row) const
{
//    row number out of range
    if ((row == 0) || (static_cast<unsigned>(abs(row)) >= row_number)) {
        return false;
    }

//    incorrect row parameter
    if (card.row() == Row::any) {
        if ((card.role() != Role::modificator)) {
            return false;
        }
        return true;
    }

//    incorrect line of fire
    if (static_cast<int>(card.row()) != abs(row)) {
        return false;
    }

//    incorrect rat placement
    if (card.role() == Role::fighter) {
        if ((card.rat() && (row > 0)) || (!card.rat() && (row < 0))) {
            return false;
        }
    }

    return true;
}


bool Field::fromHandToRow(const int row, const unsigned hand_position)
{
//    incorrect position in hand
    if (hand_position >= hand.size()) {
        return false;
    }
    Card card(hand.at(hand_position));

    if (!correctPlacement(card, row)) {
        return false;
    }

    int abs_row = abs(row);

//    modificator placement
    if (card.row() == Row::any) {
        if (card.value() == 0) {
            ally_rows[abs_row].push_back(card);
            enemy_rows[abs_row].push_back(card);
        }
        else {
            if (row > 0) {
                ally_rows[abs_row].push_back(card);
            }
            else {
                enemy_rows[abs_row].push_back(card);
            }
        }
        return true;
    }

//    any other card
    if (row > 0) {
        ally_rows[abs_row].push_back(card);
    }
    else {
        enemy_rows[abs_row].push_back(card);
    }
    hand.erase(hand.begin() + hand_position);

//    take two cards if rat
    if ((card.role() == Role::fighter) && card.rat()) {
        fromPoolToHand();
        fromPoolToHand();
    }

    return true;
}

bool Field::fromPoolToHand()
{
    if (pool.emptyAvailible()) {
        return false;
    }
    Card card(pool.getCard());
    hand.push_back(card);
    return true;
}

bool Field::fromEnemyToRow(const unsigned id, const int row)
{
    Card card(id);

//    decrement number of enemy cards
    --enemy_hand;

    if (!correctPlacement(card, row)) {
        return false;
    }

    const int abs_row = abs(row);

//    modificator placement
    if (card.row() == Row::any) {
        if (card.value() == 0) {
            ally_rows[abs_row].push_back(card);
            enemy_rows[abs_row].push_back(card);
        }
        else {
            if (row > 0) {
                ally_rows[abs_row].push_back(card);
            }
            else {
                enemy_rows[abs_row].push_back(card);
            }
        }
        return true;
    }

//    any other card
    if (row > 0) {
        ally_rows[abs_row].push_back(card);
    }
    else {
        enemy_rows[abs_row].push_back(card);
    }

//    take two cards if rat
    if ((card.role() == Role::fighter) && (card.rat())) {
        enemy_hand += 2;
    }

    return true;
}
