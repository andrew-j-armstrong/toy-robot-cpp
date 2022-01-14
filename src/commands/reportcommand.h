#ifndef TOYROBOT_REPORTCOMMAND_H_
#define TOYROBOT_REPORTCOMMAND_H_

#include <memory>

#include "icommand.h"
#include "../model/irobot.h"
#include "../model/ireporter.h"

namespace ToyRobot
{
    class ReportCommand : public ICommand
    {
    public:
        ReportCommand(std::shared_ptr<IRobot> robot, std::shared_ptr<IReporter> reporter);
        virtual ~ReportCommand();

        bool execute() const override;

    protected:
        std::shared_ptr<IRobot> m_robot;
        std::shared_ptr<IReporter> m_reporter;
    };
}

#endif
