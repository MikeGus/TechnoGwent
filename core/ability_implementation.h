#ifndef ABILITY_IMPLEMENTATION_H
#define ABILITY_IMPLEMENTATION_H

#include <functional>
#include "../desk.h"

class Ability_impl
{
    public:
        explicit Ability_impl() = default;
        explicit Ability_impl(const unsigned id);
        explicit Ability_impl(const Ability_impl& other) = default;

        virtual ~Ability_impl() = default;

        void execute(Desk& desk) const;

    private:
        std::function<void(Desk&)> _function;

};

#endif // ABILITY_IMPLEMENTATION_H
