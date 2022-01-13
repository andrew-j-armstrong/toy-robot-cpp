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
    if (!is_placed())
        return false;

    int x = m_x;
    int y = m_y;

    switch(m_facing)
    {
    case North:
        y++;
        break;
    case East:
        x++;
        break;
    case South:
        y--;
        break;
    case West:
        x--;
        break;
    default:
        return false;
        break;
    }

    if (!m_surface->is_valid_location(x, y))
        return false;

    m_x = x;
    m_y = y;

    return true;
}

bool Robot::left()
{
    if (!is_placed())
        return false;

    // Could potentially use m_facing = (m_facing + 3) % 4;
    // However I think that's less readable, hence opted for the switch statement.
    switch (m_facing)
    {
    case North:
        m_facing = West;
        return true;
    case East:
        m_facing = North;
        return true;
    case South:
        m_facing = East;
        return true;
    case West:
        m_facing = South;
        return true;
    default:
        return false;
    }
}

bool Robot::right()
{
    if (!is_placed())
        return false;

    // Could potentially use m_facing = (m_facing + 1) % 4;
    // However I think that's less readable, hence opted for the switch statement.
    switch (m_facing)
    {
    case North:
        m_facing = East;
        return true;
    case East:
        m_facing = South;
        return true;
    case South:
        m_facing = West;
        return true;
    case West:
        m_facing = North;
        return true;
    default:
        return false;
    }
}

bool Robot::report(IReporter &reporter) const
{
    if (!is_placed())
        return false;

    reporter.report(m_x, m_y, m_facing);
    return true;
}
