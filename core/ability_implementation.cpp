#include "ability_implementation.h"

// availible_commands

void ability_0(const Field& field)
{
    return;
}

void ability_1(const Field& field)
{
    return;
}

void ability_2(const Field &field)
{
    return;
}


Ability_impl::Ability_impl(const unsigned id)
{
    void (*func)(const Field&);
    switch (id) {
        case 0:
            func = ability_0;
            break;
        case 1:
            func = ability_1;
            break;
        case 2:
            func = ability_2;
            break;

        default:
            throw (std::logic_error("Wrong argument passed to constructor!"));
            break;
    }

    std::function<void (const Field&)> f(func);
    this->_function = f;
}

void Ability_impl::execute(const Field& field) const
{
    this->_function(field);
}
