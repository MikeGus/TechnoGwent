#ifndef ABILITY_H
#define ABILITY_H

#include "ability_inplementation.h"

//enum class Ability
//{
//    ability_1 // Mb not enum class but class w/ functions;
//    //TODO
//};

class Ability
{
    public:
        void execute(Field& field);

    private:
        Ability_impl realization;
};




#endif // ABILITY_H
