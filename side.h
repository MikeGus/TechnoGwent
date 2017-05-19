#ifndef SIDE_H
#define SIDE_H

#include <vector>
#include <memory>
#include "card.h"

struct Side // no need for class
{
    public:
        std::vector<std::vector<std::shared_ptr<Card>>> rows;
};

#endif // SIDE_H
