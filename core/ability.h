#ifndef ABILITY_H
#define ABILITY_H

#include "ability_implementation.h"
class Ability
{
    public:
        explicit Ability(const unsigned id);
        explicit Ability(const Ability& other) = default;

        virtual ~Ability() = default;

        void execute(Desk& field) const;

    private:
        Ability_impl _realization;
};

#endif // ABILITY_H
