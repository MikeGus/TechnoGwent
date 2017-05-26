#ifndef COMMAND_INIT_H
#define COMMAND_INIT_H

#include "command.h"

class CommandInit : public Command
{
    public:
        CommandInit(GameWindow*, Field*, const unsigned mixKey);
        virtual ~CommandInit() {}

        virtual void execute();
    private:
        unsigned seed;
};

#endif // COMMAND_INIT_H
