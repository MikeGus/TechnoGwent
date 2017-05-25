#include "fighter.h"


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

