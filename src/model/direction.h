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
        MaxDirection = West,
    };

    std::string to_string(Direction d);
}

#endif
