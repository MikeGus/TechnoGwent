#ifndef DESK_H
#define DESK_H

#include <vector>
#include "cardpool.h"

#include <iostream>

const unsigned row_number = 3;

class Desk
{
    typedef std::vector<Card> Deck;
    public:
        Deck ally_rows[row_number];
        Deck enemy_rows[row_number];
        CardPool pool;
};

#endif // DESK_H
