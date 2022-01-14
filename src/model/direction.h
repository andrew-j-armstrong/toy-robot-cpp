#ifndef TOYROBOT_DIRECTION_H_
#define TOYROBOT_DIRECTION_H_

#include <string>

namespace ToyRobot
{
    enum Direction
    {
        UnknownDirection = 0,
        North,
        East,
        South,
        West,
        MinDirection = North,
        MaxDirection = West,
    };

    std::string to_string(Direction direction);
    Direction from_string(const std::string &input);
    bool is_valid_direction(Direction direction);
}

#endif
