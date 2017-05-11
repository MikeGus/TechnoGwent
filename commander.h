#ifndef COMMANDER_H
#define COMMANDER_H

#include "card.h"
#include "ability.h"

class Commander : public Card
{
    public:
        Commander() = delete;
        explicit Commander(const unsigned card_id);
        explicit Commander(const Commander& other) = default;
        virtual ~Commander() = default;

        Ability get_ability() const;
        bool ability_used() const;

    protected:
        Ability ability;
        bool used;
};


Commander::Commander(const unsigned card_id) : Card(card_id)
{
    //if Card constructor fails, exception will be thrown, else:
    //TODO set multiplicator from db
}


Ability Commander::get_ability() const
{
    return ability;
}


bool Commander::ability_used() const
{
    return used;
}


#endif // COMMANDER_H
