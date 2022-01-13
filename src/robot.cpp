#include "robot.h"

using namespace ToyRobot;

Robot::Robot()
: m_x(0)
, m_y(0)
, m_facing(UnknownDirection)
{
}

Robot::Robot(std::shared_ptr<ISurface> surface, int x, int y, Direction facing)
: m_surface(surface)
, m_x(x)
, m_y(y)
, m_facing(facing)
{
}

bool Robot::place(std::shared_ptr<ISurface> surface, int x, int y, Direction facing)
{
    if (!surface || !surface->is_valid_location(x, y))
        return false;

    m_surface = surface;
    m_x = x;
    m_y = y;
    m_facing = facing;

    return true;
}

bool Robot::move()
{
    return true;
}

void Robot::left()
{
}

void Robot::right()
{
}

void Robot::report(IReporter &reporter) const
{
}
