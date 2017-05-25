#ifndef ABILITY_IMPLEMENTATION_H
#define ABILITY_IMPLEMENTATION_H

#include <functional>

class Field;


class Ability_impl
{
    public:
        explicit Ability_impl() = default;
        explicit Ability_impl(const unsigned id);
        explicit Ability_impl(const Ability_impl& other) = default;

        virtual ~Ability_impl() = default;

        void execute(const Field& field) const;

    private:
        std::function<void(const Field&)> _function;

};

#endif // ABILITY_IMPLEMENTATION_H
