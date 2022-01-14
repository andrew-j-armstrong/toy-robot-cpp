#ifndef TOYROBOT_EXITCOMMAND_H_
#define TOYROBOT_EXITCOMMAND_H_

#include <memory>

#include "icommand.h"

namespace ToyRobot
{
    class ExitCommand : public ICommand
    {
    public:
        ExitCommand();
        virtual ~ExitCommand();

        bool execute() const override;

    protected:
    };
}

#endif
