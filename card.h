#ifndef CARD_H
#define CARD_H

#include "role.h"
#include "row.h"
#include "alliance.h"
#include <utility>

class Card
{
    public:
        Card() = default;
        explicit Card(const unsigned card_id);
        explicit Card(const Card& other) = default;
        virtual ~Card() = default;

        Card& operator=(const Card &other);

        Row get_row() const;
        Role get_role() const;
        Alliance get_alliance() const;
        unsigned get_id() const;

    protected:
        Row row;
        Role role;
        Alliance alliance;
        unsigned id;
};


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


#endif // CARD_H
