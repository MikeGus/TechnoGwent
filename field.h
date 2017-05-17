#ifndef FIELD_H
#define FIELD_H

#include "side.h"
#include "hand.h"

struct Field
{
    public:
        Side allied_forces;
        Side enemy_forces;

        Commander allied_commander;
        Commander enemy_commander;

        Hand hand;
};

#endif // FIELD_H
