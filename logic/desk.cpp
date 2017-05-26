#include "desk.h"

Desk::Desk(const unsigned mixKey) : pool(mixKey) {}

void Desk::clear()
{
    for (unsigned i = 0; i < row_number; ++i) {
        ally_rows[i].clear();
        enemy_rows[i].clear();
    }
}
