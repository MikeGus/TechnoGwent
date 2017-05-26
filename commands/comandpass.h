#ifndef COMMAND_PASS_H
#define COMMAND_PASS_H

#include "command.h"

class CommandPass : public Command
{
    public:
        CommandPass(GameWindow*, Field*, const unsigned mixKey);
        virtual ~CommandInit() {}

        virtual void execute();
    private:
        unsigned seed;
};

#endif // COMMAND_INIT_H
