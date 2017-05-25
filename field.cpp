#include "field.h"

unsigned Field::strength(unsigned row) const
{
    if (row >= row_number) {
        throw(std::logic_error("Wrong row number!"));
    }

    unsigned str = 0;
    unsigned count = 0;

    unsigned modificator = 1;
    bool zero_modificator = false;

//    check every card in a row
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
    for (unsigned i = 0; i < row_number / 2; ++i) {
        str += strength(i);
    }
    return str;
}


unsigned Field::enemyStrength() const
{
    unsigned str = 0;
    for (unsigned i = row_number / 2; i < row_number; ++i) {
        str += strength(i);
    }
    return str;
}
