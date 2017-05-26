#include "commandrecieve.h"

CommandRecieve::CommandRecieve(GameWindow* window, Field* field, unsigned id, int row) : id(id), row(row)
{
    reciever_window = window;
    reciever_field = field;
}

void CommandRecieve::execute()
{
    reciever_field->fromEnemyToRow(row, id);
}
