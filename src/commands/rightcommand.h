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
        RightCommand(std::shared_ptr<IRobot> robot);
        virtual ~RightCommand();

        bool execute() const override;

    protected:
        std::shared_ptr<IRobot> m_robot;
    };
}

#endif
