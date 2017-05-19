#include "card.h"


Card::Card(const unsigned card_id)
{
    id = card_id;

    pt::ptree root;
    pt::read_json("id_type.dat", root);
    pt::ptree card_list = root.get_child("cards");

    if (card_id >= card_list.size()) {
        throw std::logic_error("Card id out of range!");
    }

    for (pt::ptree::value_type& c : card_list) {
        auto& data = c.second.get_child("id");

        if ((unsigned) std::stoi(data.data()) == card_id) {
            this->alliance = (Alliance) std::stoi(c.second.get_child("alliance").data());
            this->role = (Role) std::stoi(c.second.get_child("role").data());
            this->row = (Row) std::stoi(c.second.get_child("row").data());
            break;
        }
    }
}


Card& Card::operator =(const Card& other)
{
    row = other.row;
    role = other.role;
    alliance = other.alliance;
    id = other.id;

    return *this;
}


Row Card::get_row() const
{
    return row;
}


Role Card::get_role() const
{
    return role;
}


Alliance Card::get_alliance() const
{
    return alliance;
}


unsigned Card::get_id() const
{
    return id;
}

