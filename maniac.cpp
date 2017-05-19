#include "maniac.h"


Maniac::Maniac(const unsigned card_id) : Card(card_id)
{
    if (this->role != Role::maniac) {
        throw std::logic_error("Wrong card type!");
    }

    pt::ptree root;
    pt::read_json("id_type.dat", root);
    pt::ptree card_list = root.get_child("cards");

    for (pt::ptree::value_type& c : card_list) {
        auto& data = c.second.get_child("id");

        if ((unsigned) std::stoi(data.data()) == card_id) {
            this->strength = std::stoi(c.second.get_child("strength").data());
            this->minimal_strength = std::stoi(c.second.get_child("min_strength").data());
            break;
        }
    }
}


unsigned Maniac::get_strength() const
{
    return strength;
}


unsigned Maniac::get_minimal_strength() const
{
    return minimal_strength;
}
