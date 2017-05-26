#include "ability.h"

Ability::Ability(const unsigned id) : _realization(id) {}


void Ability::execute(Desk& field) const
{
    _realization.execute(field);
}
