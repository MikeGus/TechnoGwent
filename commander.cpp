#include "commander.h"


Commander::Commander(const unsigned id): _ability(id), _id(id), _used(false) {}


bool Commander::used() const
{
    return _used;
}


unsigned Commander::id() const
{
    return _id;
}


void Commander::use_ability(Field& field)
{
    _ability.execute(field);
    _used = true;
}
