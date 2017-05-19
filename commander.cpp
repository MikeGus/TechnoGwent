#include "commander.h"

Commander::Commander(const unsigned card_id) : Card(card_id)
{
    if (this->role != Role::commander) {
        throw std::logic_error("Wrong card type!");
    }
}


Ability Commander::get_ability() const
{
    return ability;
}


bool Commander::ability_used() const
{
    return used;
}
