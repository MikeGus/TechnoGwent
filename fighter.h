#ifndef FIGHTER_H
#define FIGHTER_H

#include "card.h"
#include "effect.h"

class Fighter : public Card
{
    public:
        Fighter() = delete;
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


Fighter::Fighter(const unsigned card_id) : Card(card_id)
{
    //if Card constructor fails, exception will be thrown, else:
    //TODO set multiplicator from db
}


unsigned Fighter::get_strength() const
{
    return strength;
}


bool Fighter::is_golden() const
{
    return golden;
}


bool Fighter::is_rat() const
{
    return rat;
}


Effect Fighter::get_effect() const
{
    return effect;
}


#endif // FIGHTER_H
