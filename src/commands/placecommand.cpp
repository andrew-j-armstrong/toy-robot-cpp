#include "placecommand.h"

#include <stdexcept>

using namespace ToyRobot;

PlaceCommand::PlaceCommand(std::shared_ptr<IRobot> robot, std::shared_ptr<ISurface> surface, int x, int y, Direction facing)
: m_robot(std::move(robot))
, m_surface(std::move(surface))
, m_x(x)
, m_y(y)
, m_facing(facing)
{
    if (!m_robot)
        throw std::invalid_argument("robot");
    if (!m_surface)
        throw std::invalid_argument("surface");
}

PlaceCommand::~PlaceCommand()
{
}

bool PlaceCommand::execute() const
{
    return m_robot->place(m_surface, m_x, m_y, m_facing);
}
