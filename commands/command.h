#ifndef COMMAND_H
#define COMMAND_H

#include "../gamewindow.h"
#include "../logic/field.h"

class Command
{
    public:
        virtual ~Command() {}

        virtual void execute() = 0;

    protected:
        GameWindow* reciever_window;
        Field* reciever_field;

};


#endif // COMMAND_H
