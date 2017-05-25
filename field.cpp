#include "field.h"

unsigned Field::strength(int row) const
{
    if ((static_cast<unsigned>(abs(row)) >= row_number) || (row == 0)) {
        throw(std::logic_error("Wrong row number!"));
    }

    unsigned str = 0;
    unsigned count = 0;

    unsigned modificator = 1;
    bool zero_modificator = false;

//    check every card in a row
    const Deck* rows(ally_rows);
    if (row < 0) {
        rows = enemy_rows;
    }

    for (const Card& card : rows[row]) {
        if (card.role() == Role::fighter || card.role() == Role::maniac) {
            str += card.value();
            ++count;
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

bool Field::fromHandToRow(unsigned hand_position, int row)
{
//    incorrect row values
    if ((row == 0) || (static_cast<unsigned>(abs(row)) >= (row_number))) {
        return false;
    }
//    incorrect position in hand
    if (hand_position >= hand.size()) {
        return false;
    }

    Card card(hand.at(hand_position));

//    incorrect placement of "rat"
    if ((card.rat() && (row > 0)) || (!card.rat() && (row < 0))) {
        return false;
    }

//    incorrect row for this type
    if (static_cast<int> (card.role()) != abs(row)) {
        return false;
    }

//    everything ok
    if (row > 0) {
        ally_rows[row].push_back(card);
    }
    else {
        enemy_rows[row].push_back(card);
    }

    hand.erase(hand.begin() + hand_position);

    return true;
}
