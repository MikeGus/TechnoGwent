#include "card.h"

Card::Card(const unsigned card_id)
{
    //TODO search for id in base, check if correct
    id = card_id;
    //TODO copy of data from base
}


Card& Card::operator =(const Card& other)
{
    row = other.row;
    role = other.role;
    alliance = other.alliance;
    id = other.id;

    return *this;
}


Row Card::get_row() const
{
    return row;
}


Role Card::get_role() const
{
    return role;
}


Alliance Card::get_alliance() const
{
    return alliance;
}


unsigned Card::get_id() const
{
    return id;
}
