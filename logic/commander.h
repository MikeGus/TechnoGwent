#ifndef COMMANDER_H
#define COMMANDER_H

#include "card.h"
#include "core/ability.h"

class Commander
{
    public:
        explicit Commander(const unsigned id = 0);

        explicit Commander(const Commander& other) = default;
        virtual ~Commander() = default;

        bool used() const;
        unsigned id() const;

        void useAbility(Desk& desk);

    private:
        Ability _ability;
        unsigned _id = 0;
        bool _used = false;
};





#endif // COMMANDER_H
