#ifndef TOYROBOT_LEFTCOMMAND_H_
#define TOYROBOT_LEFTCOMMAND_H_

#include <memory>

#include "icommand.h"
#include "../model/irobot.h"

namespace ToyRobot
{
    class LeftCommand : public ICommand
    {
    public:
        // The constructor of LeftCommand can throw an exception if the robot is invalid
        LeftCommand(std::shared_ptr<IRobot> robot);
        virtual ~LeftCommand();

        bool execute() const override;

    protected:
        std::shared_ptr<IRobot> m_robot;
    };
}

#endif
