#ifndef SIDE_H
#define SIDE_H

#include <vector>
#include <memory>
#include "card.h"
#include "fighter.h"
#include "modificator.h"

struct Side // no need for class
{
    public:
        std::vector<std::vector<std::shared_ptr<Card>>> rows;

        unsigned get_row_strength(unsigned row);
        unsigned calculate_fighters_strength(std::vector<std::shared_ptr<Card>>& row);
};

#endif // SIDE_H
