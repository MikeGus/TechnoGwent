#ifndef MODIFICATOR_H
#define MODIFICATOR_H

#include "card.h"

class Modificator : public Card
{
    public:
        Modificator() = delete;
        explicit Modificator(const unsigned card_id);
        explicit Modificator(const Modificator& other) = default;
        virtual ~Modificator() = default;

        unsigned get_multiplicator() const;

    protected:
        unsigned multiplicator;
};



#endif // MODIFICATOR_H
