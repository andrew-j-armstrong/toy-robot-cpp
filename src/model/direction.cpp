#include "direction.h"

using namespace ToyRobot;

std::string ToyRobot::to_string(Direction d)
{
    switch(d)
    {
    case North:
        return "North";
    case West:
        return "West";
    case South:
        return "South";
    case East:
        return "East";
    default:
        return "<Unknown>";
    }
}
