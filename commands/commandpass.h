#ifndef COMMANDPASS_H
#define COMMANDPASS_H

#include "command.h"

class CommandPass : public Command
{
    public:
        CommandPass(GameWindow*, Field*);
        virtual ~CommandPass() {}

        virtual void execute();
};

#endif // COMMANDPASS_H
