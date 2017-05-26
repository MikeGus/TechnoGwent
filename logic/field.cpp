#include "field.h"

Field::Field(const unsigned mixKey, const unsigned commander_id, const unsigned enemy_commander_id) :
     desk(mixKey), ally(commander_id), enemy(enemy_commander_id), enemy_hand(10), ally_passed(false), enemy_passed(false), round(1),
     round_won(0), round_lost(0)
{
    for (unsigned i = 0; i < 10; ++i) {
        fromPoolToHand();
    }
}



unsigned Field::strength(const int row) const
{
    if ((static_cast<unsigned>(abs(row)) >= row_number) || (row == 0)) {
        throw(std::logic_error("Wrong row number!"));
    }

    unsigned str = 0;
    unsigned count = 0;

    unsigned golden = 0;

    unsigned modificator = 1;
    bool zero_modificator = false;

//    check every card in a row
    const Deck* rows(desk.ally_rows);
    if (row < 0) {
        rows = desk.enemy_rows;
    }

    for (const Card& card : rows[row]) {
        if (card.role() == Role::fighter || card.role() == Role::maniac) {
            if (card.golden()) {
                golden += card.value();
            }
            else {
                str += card.value();
                ++count;
            }
        }
        else if (card.role() == Role::modificator) {
            if (card.value() == 0) {
                zero_modificator = true;
            }
            else {
                modificator *= card.value();
            }
        }
    }

    unsigned result = str;

    if (zero_modificator) {
        result = count;
    }

    result *= modificator;
    result += golden;

    return result;
}

unsigned Field::allyStrength() const
{
    unsigned str = 0;
    for (unsigned i = 0; i < row_number; ++i) {
        str += strength(i);
    }
    return str;
}


unsigned Field::enemyStrength() const
{
    unsigned str = 0;
    for (unsigned i = 1 - row_number; i < 1; ++i) {
        str += strength(i);
    }
    return str;
}

bool Field::correctPlacement(const Card& card, const int row) const
{
//    row number out of range
    if ((row == 0) || (static_cast<unsigned>(abs(row)) >= row_number)) {
        return false;
    }

//    incorrect row parameter
    if (card.row() == Row::any) {
        if ((card.role() != Role::modificator)) {
            return false;
        }
        return true;
    }

//    incorrect line of fire
    if (static_cast<int>(card.row()) != abs(row)) {
        return false;
    }

//    incorrect rat placement
    if (card.role() == Role::fighter) {
        if ((card.rat() && (row > 0)) || (!card.rat() && (row < 0))) {
            return false;
        }
    }

    return true;
}

void Field::pass()
{
    ally_passed = true;
}


bool Field::nextRound()
{
    if (ally_passed && enemy_passed) {
        ally_passed = enemy_passed = false;
        ++round;

        if (roundWinner() > 0) {
            ++round_won;
        }
        else if (roundWinner() < 0) {
            ++round_lost;
        }

        desk.clear();

        return true;
    }
    return false;
}

//return -1 if lost 1 if won 0 if even
int Field::roundWinner()
{
    unsigned ally_str = allyStrength();
    unsigned enemy_str = enemyStrength();

    if (ally_str > enemy_str) {
        return 1;
    }
    else if (ally_str < enemy_str) {
        return -1;
    }
    return 0;
}


bool Field::finishGame()
{
    if (round == number_of_rounds && ally_passed && enemy_passed) {
//        insert logic
        return true;
    }
    return false;
}


bool Field::fromHandToRow(const int row, const unsigned hand_position)
{
//    incorrect position in hand
    if (hand_position >= hand.size()) {
        return false;
    }
    Card card(hand.at(hand_position));

    if (!correctPlacement(card, row)) {
        return false;
    }

    int abs_row = abs(row);

//    modificator placement
    if (card.row() == Row::any) {
        if (card.value() == 0) {
            desk.ally_rows[abs_row].push_back(card);
            desk.enemy_rows[abs_row].push_back(card);
        }
        else {
            if (row > 0) {
                desk.ally_rows[abs_row].push_back(card);
            }
            else {
                desk.enemy_rows[abs_row].push_back(card);
            }
        }
        return true;
    }

//    any other card
    if (row > 0) {
        desk.ally_rows[abs_row].push_back(card);
    }
    else {
        desk.enemy_rows[abs_row].push_back(card);
    }
    hand.erase(hand.begin() + hand_position);

//    take two cards if rat
    if ((card.role() == Role::fighter) && card.rat()) {
        fromPoolToHand();
        fromPoolToHand();
    }

    return true;
}

bool Field::fromPoolToHand()
{
    if (desk.pool.emptyAvailible()) {
        return false;
    }
    Card card(desk.pool.getCard());
    hand.push_back(card);
    return true;
}

bool Field::fromEnemyToRow(const int row, const unsigned id)
{
    Card card(id);

    if (card.role() == Role::pass) {
        enemy_passed = true;
        return true;
    }

//    decrement number of enemy cards
    --enemy_hand;

    if (!correctPlacement(card, row)) {
        return false;
    }

    const int abs_row = abs(row);

//    modificator placement
    if (card.row() == Row::any) {
        if (card.value() == 0) {
            desk.ally_rows[abs_row].push_back(card);
            desk.enemy_rows[abs_row].push_back(card);
        }
        else {
            if (row > 0) {
                desk.ally_rows[abs_row].push_back(card);
            }
            else {
                desk.enemy_rows[abs_row].push_back(card);
            }
        }
        return true;
    }

//    any other card
    if (row > 0) {
        desk.ally_rows[abs_row].push_back(card);
    }
    else {
        desk.enemy_rows[abs_row].push_back(card);
    }

//    take two cards if rat
    if ((card.role() == Role::fighter) && (card.rat())) {
        enemy_hand += 2;
    }

    return true;
}

