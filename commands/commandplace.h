#ifndef COMMANDPLACE_H
#define COMMANDPLACE_H

#include "command.h"

class CommandPlace : public Command
{
    public:
        CommandPlace(GameWindow*, Field*, int h_pos, int row);
        virtual ~CommandPlace() {}

        virtual void execute();

    private:
        int h_pos = 0;
        int row = 0;
};

#endif // COMMANDPLACE_H
