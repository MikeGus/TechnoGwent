#ifndef SIDE_H
#define SIDE_H

#include <vector>
#include <memory>
#include "card.h"

struct Side // no need for class
{
    public:
        std::vector<std::shared_ptr<Card>> melee_row;
        std::vector<std::shared_ptr<Card>> markman_row;
        std::vector<std::shared_ptr<Card>> vehicle_row;
        std::vector<std::shared_ptr<Card>> officer_row;
};

#endif // SIDE_H
