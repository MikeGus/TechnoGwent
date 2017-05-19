#include "side.h"


unsigned Side::calculate_fighters_strength(std::vector<std::shared_ptr<Card>>& row)
{
    unsigned str = 0;
    for (std::shared_ptr<Card>& elem : row) {
        Card* raw = elem.get();
        if (raw->get_role() == Role::fighter) {
            Fighter* raw_fighter = (Fighter*) raw;
            str += raw_fighter->get_strength();
        }
    }

    return str;
}


unsigned Side::get_row_strength(unsigned row)
{
    if (row > 4) {
        return 0;
    }
    std::vector<std::shared_ptr<Card>>& used_row(rows[row]);

    unsigned str = calculate_fighters_strength(used_row);
    unsigned mod = 1;

    for (std::shared_ptr<Card>& elem : used_row) {
        Card* raw = elem.get();
        if (raw->get_role() == Role::modificator) {
            Modificator* raw_modificator = (Modificator*) raw;
            if (raw_modificator->get_multiplicator()) {
                mod *= raw_modificator->get_multiplicator();
            }
            else {
                str = 1;
            }
        }
    }

    str *= mod;
    return str;
}
