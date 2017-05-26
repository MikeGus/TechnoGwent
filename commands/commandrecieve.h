#ifndef COMMANDRECIEVE_H
#define COMMANDRECIEVE_H

#include "command.h"

class CommandRecieve : public Command
{
    public:
        CommandRecieve(GameWindow*, Field*, unsigned id, int row);
        virtual ~CommandRecieve() {}

        virtual void execute();

    private:
        int id = 0;
        int row = 0;
};

#endif // COMMANDRECIEVE_H
