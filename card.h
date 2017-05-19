#ifndef CARD_H
#define CARD_H

#include <utility>
#include "role.h"
#include "row.h"
#include "alliance.h"

class Card
{
    public:
        Card() = default;
        explicit Card(const unsigned card_id);
        Card(const Card& other) = default;
        virtual ~Card() = default;

        Card& operator=(const Card &other);

        Row get_row() const;
        Role get_role() const;
        Alliance get_alliance() const;
        unsigned get_id() const;

    protected:
        Row row;
        Role role;
        Alliance alliance;
        unsigned id;
};


#endif // CARD_H
