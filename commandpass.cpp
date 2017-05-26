#include "commandpass.h"

CommandPass::CommandPass(GameWindow* window, Field* field)
{
    reciever_window = window;
    reciever_field = field;
}

void CommandPass::execute()
{
    reciever_field->pass();
    if (reciever_field->nextRound()) {
        if (reciever_field->finishGame()) {
//            insert finish game sequence
            return;
        }
        else {
//            insert paint sequence
        }
    }
}
