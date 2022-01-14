#ifndef TOYROBOT_ICOMMANDFACTORY_H_
#define TOYROBOT_ICOMMANDFACTORY_H_

#include "icommand.h"
#include "../model/irobot.h"
#include "../model/isurface.h"
#include "../model/ireporter.h"

namespace ToyRobot
{
    class ICommandFactory
    {
    public:
        virtual ~ICommandFactory() {}

        virtual std::unique_ptr<ICommand> new_move_command() const = 0;
        virtual std::unique_ptr<ICommand> new_left_command() const = 0;
        virtual std::unique_ptr<ICommand> new_right_command() const = 0;
        virtual std::unique_ptr<ICommand> new_report_command() const = 0;
        virtual std::unique_ptr<ICommand> new_exit_command() const = 0;
        virtual std::unique_ptr<ICommand> new_place_command(int x, int y, Direction facing) const = 0;

    protected:
        ICommandFactory() {}
    };
}

#endif
