#include "direction.h"

#include "../util/stringutil.h"

using namespace ToyRobot;

std::string ToyRobot::to_string(Direction direction)
{
    switch(direction)
    {
    case North:
        return "NORTH";
    case West:
        return "WEST";
    case South:
        return "SOUTH";
    case East:
        return "EAST";
    default:
        return "<Unknown>";
    }
}

Direction ToyRobot::from_string(const std::string &input)
{
    std::string lowercaseInput = to_lowercase(trim(input));
    if (lowercaseInput == "north")
        return North;
    else if (lowercaseInput == "east")
        return East;
    else if (lowercaseInput == "south")
        return South;
    else if (lowercaseInput == "west")
        return West;

    return UnknownDirection;
}

bool ToyRobot::is_valid_direction(Direction direction)
{
    return direction >= MinDirection && direction <= MaxDirection;
}