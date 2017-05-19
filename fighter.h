#ifndef FIGHTER_H
#define FIGHTER_H

#include "card.h"
#include "effect.h"

class Fighter : public Card
{
    public:
        Fighter() = default;
        explicit Fighter(const unsigned card_id);
        explicit Fighter(const Fighter& other) = default;
        virtual ~Fighter() = default;

        unsigned get_strength() const;
        bool is_golden() const;
        bool is_rat() const;
        Effect get_effect() const;

    protected:
        unsigned strength;
        bool golden;
        bool rat;
        Effect effect;
};


#endif // FIGHTER_H
