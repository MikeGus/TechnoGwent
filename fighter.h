#ifndef FIGHTER_H
#define FIGHTER_H

#include "card.h"
#include "effect.h"

class Fighter : public Card
{
    public:
        Fighter() = default;
        explicit Fighter(const unsigned card_id);
        explicit Fighter(const Fighter& other) = default;
        virtual ~Fighter() = default;

        unsigned get_strength() const;
        bool is_golden() const;
        bool is_rat() const;
        Effect get_effect() const;

    protected:
        unsigned strength;
        bool golden;
        bool rat;
        Effect effect;
};


Fighter::Fighter(const unsigned card_id) : Card(card_id)
{
    if (this->role != Role::fighter) {
        throw std::logic_error("Wrong card type!");
    }

    pt::ptree root;
    pt::read_json("id_type.dat", root);
    pt::ptree card_list = root.get_child("cards");

    for (pt::ptree::value_type& c : card_list) {
        auto& data = c.second.get_child("id");

        if ((unsigned) std::stoi(data.data()) == card_id) {
            this->strength = std::stoi(c.second.get_child("strength").data());
            this->golden = c.second.get_child("golden").data() == "true";
            this->rat = c.second.get_child("rat").data() == "true";
            this->effect = (Effect) std::stoi(c.second.get_child("effect").data());
            break;
        }
    }
}


unsigned Fighter::get_strength() const
{
    return strength;
}


bool Fighter::is_golden() const
{
    return golden;
}


bool Fighter::is_rat() const
{
    return rat;
}


Effect Fighter::get_effect() const
{
    return effect;
}


#endif // FIGHTER_H
