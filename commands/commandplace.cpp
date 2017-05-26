#include "commandplace.h"

CommandPlace::CommandPlace(GameWindow* window, Field* field, int h_pos, int row) : h_pos(h_pos), row(row)
{
    reciever_window = window;
    reciever_field = field;
}

void CommandPlace::execute()
{
    reciever_field->fromHandToRow(row, h_pos);
}
