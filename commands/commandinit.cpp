#include "commandinit.h"

CommandInit::CommandInit(GameWindow* window, Field* field, const unsigned mixKey) : seed(mixKey)
{
    reciever_window = window;
    reciever_field = field;
}

void CommandInit::execute()
{
//    data for repaint
    std::vector<Card> hand(reciever_field->hand);
    Commander ally_commander(reciever_field->ally);
    Commander enemy_commander(reciever_field->enemy);
//    todo paint
}
