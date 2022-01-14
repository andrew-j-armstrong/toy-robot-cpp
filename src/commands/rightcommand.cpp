#include "rightcommand.h"

#include <stdexcept>

using namespace ToyRobot;

RightCommand::RightCommand(std::shared_ptr<IRobot> robot)
: m_robot(std::move(robot))
{
    if (!m_robot)
        throw std::invalid_argument("robot");
}

RightCommand::~RightCommand()
{
}

bool RightCommand::execute() const
{
    return m_robot->right();
}
