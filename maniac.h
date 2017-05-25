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



#endif // MANIAC_H
