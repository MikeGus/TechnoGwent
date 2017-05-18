#ifndef MODIFICATOR_H
#define MODIFICATOR_H

#include "card.h"

class Modificator : public Card
{
    public:
        Modificator() = delete;
        explicit Modificator(const unsigned card_id);
        explicit Modificator(const Modificator& other) = default;
        virtual ~Modificator() = default;

        unsigned get_multiplicator() const;

    protected:
        unsigned multiplicator;
};


Modificator::Modificator(const unsigned card_id) : Card(card_id)
{
    if (this->role != Role::modificator) {
        throw std::logic_error("Wrong card type!");
    }

    pt::ptree root;
    pt::read_json("id_type.dat", root);
    pt::ptree card_list = root.get_child("cards");

    for (pt::ptree::value_type& c : card_list) {
        auto& data = c.second.get_child("id");

        if ((unsigned) std::stoi(data.data()) == card_id) {
            this->multiplicator = std::stoi(c.second.get_child("multiplicator").data());
            break;
        }
    }
}


unsigned Modificator::get_multiplicator()const
{
    return multiplicator;
}


#endif // MODIFICATOR_H
