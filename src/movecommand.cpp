#include "movecommand.h"

#include <stdexcept>

using namespace ToyRobot;

MoveCommand::MoveCommand(std::shared_ptr<IRobot> robot)
: m_robot(std::move(robot))
{
    if (!m_robot)
        throw std::invalid_argument("robot");
}

MoveCommand::~MoveCommand()
{
}

bool MoveCommand::execute() const
{
    return m_robot->move();
}
