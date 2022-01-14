#include "leftcommand.h"

#include <stdexcept>

using namespace ToyRobot;

LeftCommand::LeftCommand(std::shared_ptr<IRobot> robot)
: m_robot(std::move(robot))
{
    if (!m_robot)
        throw std::invalid_argument("robot");
}

LeftCommand::~LeftCommand()
{
}

bool LeftCommand::execute() const
{
    return m_robot->left();
}
