#ifndef TOYROBOT_IROBOT_H_
#define TOYROBOT_IROBOT_H_

#include <memory>

#include "isurface.h"
#include "ireporter.h"

namespace ToyRobot
{
    // IRobot provides an interface to a robot that accepts a standard set of commands
    class IRobot
    {
    public:
        virtual ~IRobot() {}

        virtual bool place(std::shared_ptr<ISurface> surface, int x, int y, Direction facing) = 0;
        virtual bool move() = 0;
        virtual bool left() = 0;
        virtual bool right() = 0;
        virtual bool report(IReporter &reporter) const = 0;

    protected:
        IRobot() {}
    };
}

#endif
