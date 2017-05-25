#ifndef CARD_H
#define CARD_H


#include "role.h"
#include "row.h"
#include "alliance.h"
#include <utility>


#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>


#include <iostream>

namespace pt = boost::property_tree;


class Card
{
    public:
        Card() = default;
        explicit Card(const unsigned card_id);
        /*explicit*/ Card(const Card& other) = default; // Не думаю, что нам его нужно делать как explicit, на самом деле
                                                        // Либо тогда добавлять move-семантику, чтобы из функций можно было
                                                        // Возвращать копию
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
