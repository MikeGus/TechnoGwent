#ifndef CARD_H
#define CARD_H

#include "core/alliance.h"
#include "core/role.h"
#include "core/row.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

class Card
{
    public:
//        conctructor w/ data from db
        explicit Card() = default;
        explicit Card(const unsigned id);
        Card(const Card& other) = default;
        Card(Card& other) = default;
        Card& operator =(const Card& other);

        virtual ~Card() = default;

        Alliance alliance() const;
        Role role() const;
        Row row() const;
        unsigned id() const;
        unsigned value() const;
        bool golden() const;
        bool rat() const;

    private:
        Alliance _alliance = Alliance::none;
        Role _role = Role::pass;
        Row _row = Row::any;

        unsigned _id = 0;
        unsigned _value = 0;

        bool _golden = false;
        bool _rat = false;
};


#endif // CARD_H
