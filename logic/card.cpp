#include "card.h"

// constructors
Card::Card(const unsigned id) : _id(id)
{
    pt::ptree root;
    pt::read_json("data/card_db.dat", root);
    pt::ptree card_list = root.get_child("cards");

    if (this->_id >= card_list.size()) {
        throw std::logic_error("Card id out of range!");
    }

    for (pt::ptree::value_type& c : card_list) {
        auto& data = c.second.get_child("id");

        if ((unsigned) std::stoi(data.data()) == this->_id) {
            this->_alliance = static_cast<Alliance>(std::stoi(c.second.get_child("alliance").data()));
            this->_role = static_cast<Role>(std::stoi(c.second.get_child("role").data()));
            this->_row = static_cast<Row>(std::stoi(c.second.get_child("row").data()));

            if (this->_role != Role::pass) {
                this->_value = static_cast<unsigned>(std::stoi(c.second.get_child("value").data()));

                if (this->_role == Role::fighter) {
                    this->_golden = static_cast<bool>(std::stoi(c.second.get_child("golden").data()));
                    this->_rat = static_cast<bool>(std::stoi(c.second.get_child("rat").data()));
                }
            }
            break;
        }
    }
}


Card& Card::operator =(const Card& other)
{
    this->_alliance = other._alliance;
    this->_role = other._role;
    this->_row = other._row;
    this->_id = other._id;
    this->_value = other._value;
    this->_golden = other._golden;
    this->_rat = other._rat;

    return *this;
}

// getters
Alliance Card::alliance() const
{
    return _alliance;
}


Role Card::role() const
{
    return _role;
}


Row Card::row() const
{
    return _row;
}

unsigned Card::id() const
{
    return _id;
}


unsigned Card::value() const
{
    return _value;
}


bool Card::golden() const
{
    return _golden;
}


bool Card::rat() const
{
    return _rat;
}
