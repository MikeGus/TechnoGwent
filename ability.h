#ifndef ABILITY_H
#define ABILITY_H

#include <functional>

//enum class Ability
//{
//    ability_1 // Mb not enum class but class w/ functions;
//    //TODO
//};

struct Field;


typedef std::function<void(Field&)> Ability;


#endif // ABILITY_H
