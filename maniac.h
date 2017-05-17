#ifndef MANIAC_H
#define MANIAC_H

#include "card.h"

class Maniac : public Card
{
    public:
        Maniac() = default;
        explicit Maniac(const unsigned card_id);
        explicit Maniac(const Maniac& other) = default;
        virtual ~Maniac() = default;

        unsigned get_strength() const;
        unsigned get_minimal_strength() const;

    protected:
        unsigned strength;
        unsigned minimal_strength;
};


Maniac::Maniac(const unsigned card_id) : Card(card_id)
{
    //if Card constructor fails, exception will be thrown, else:
    //TODO set multiplicator from db
}


unsigned Maniac::get_strength() const
{
    return strength;
}


unsigned Maniac::get_minimal_strength() const
{
    return minimal_strength;
}


#endif // MANIAC_H
