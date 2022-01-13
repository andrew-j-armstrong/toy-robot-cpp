#ifndef TOYROBOT_MOVECOMMAND_H_
#define TOYROBOT_MOVECOMMAND_H_

#include <memory>

#include "icommand.h"
#include "irobot.h"

namespace ToyRobot
{
    class MoveCommand : public ICommand
    {
    public:
        MoveCommand(std::shared_ptr<IRobot> robot);
        virtual ~MoveCommand();

        bool execute() const override;

    protected:
        std::shared_ptr<IRobot> m_robot;
    };
}

#endif
