#ifndef TOYROBOT_COMMANDFACTORY_H_
#define TOYROBOT_COMMANDFACTORY_H_

#include "icommandfactory.h"
#include "icommand.h"
#include "../model/irobot.h"
#include "../model/isurface.h"
#include "../model/ireporter.h"

namespace ToyRobot
{
    class CommandFactory : public ICommandFactory
    {
    public:
        CommandFactory(std::shared_ptr<IRobot> robot, std::shared_ptr<IReporter> reporter, std::shared_ptr<ISurface> surface);
        virtual ~CommandFactory();

        std::unique_ptr<ICommand> new_move_command() const override;
        std::unique_ptr<ICommand> new_left_command() const override;
        std::unique_ptr<ICommand> new_right_command() const override;
        std::unique_ptr<ICommand> new_report_command() const override;
        std::unique_ptr<ICommand> new_place_command(int x, int y, Direction facing) const override;

    protected:
        std::shared_ptr<IRobot> m_robot;
        std::shared_ptr<IReporter> m_reporter;
        std::shared_ptr<ISurface> m_surface;
    };
}

#endif
