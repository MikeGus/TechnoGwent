#include "field.h"
#include "fighter.h"

bool Field::from_hand_to_side(unsigned pos, int row)
{
    std::shared_ptr<Card> card(hand.get(pos));
    Card* raw = card.get();

    if (raw->get_role() == Role::fighter) {
        Fighter* raw_figher = (Fighter*) raw;
        if (raw_figher->is_rat()) {
            if (row >= 0) {
                hand.add(card);
                return false;
            }
            else if (row < 0) {
                row = - row;
                if (row == (int) raw->get_role()) {
                    enemy_forces.rows[row].push_back(card);
                    return true;
                }
            }

        }
        else {
            if (row <= 0) {
                hand.add(card);
                return false;
            }
            else {
                if (row == (int) raw->get_role()) {
                    enemy_forces.rows[row].push_back(card);
                    return true;
                }
            }
        }
    }

    if (row == (int) raw->get_row()) {
        allied_forces.rows[row].push_back(card);
        return true;
    }

    return false;
}


void Field::rand_from_pool()
{
    srand(time(NULL));
    unsigned pos = rand() % pool.size();
    hand.add(pool[pos]);
}
