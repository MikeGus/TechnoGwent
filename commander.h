#ifndef COMMANDER_H
#define COMMANDER_H

#include "card.h"
#include "ability.h"

class Commander : public Card
{
    public:
        Commander() = default;
        explicit Commander(const unsigned card_id);
        explicit Commander(const Commander& other) = default;
        virtual ~Commander() = default;

        Ability get_ability() const;
        bool ability_used() const;

    protected:
        Ability ability;
        bool used;
};





#endif // COMMANDER_H
