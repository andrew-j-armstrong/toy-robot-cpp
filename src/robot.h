#ifndef TOYROBOT_ROBOT_H_
#define TOYROBOT_ROBOT_H_

#include <memory>

#include "direction.h"
#include "isurface.h"
#include "ireporter.h"

namespace ToyRobot
{
    class Robot
    {
    public:
        Robot();

        bool move();
        void left();
        void right();
        void report(IReporter &reporter);

    protected:
        std::shared_ptr<ISurface> m_surface;
        int m_x;
        int m_y;
        Direction m_facing;
    };
}

#endif
