#ifndef TOYROBOT_RIGHTCOMMAND_H_
#define TOYROBOT_RIGHTCOMMAND_H_

#include <memory>

#include "icommand.h"
#include "../model/irobot.h"

namespace ToyRobot
{
    class RightCommand : public ICommand
    {
    public:
        // The constructor of RightCommand can throw an exception if the robot is invalid
        RightCommand(std::shared_ptr<IRobot> robot);
        virtual ~RightCommand();

        bool execute() const override;

    protected:
        std::shared_ptr<IRobot> m_robot;
    };
}

#endif
