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
        Robot(std::shared_ptr<ISurface> surface, int x, int y, Direction facing);

        bool place(std::shared_ptr<ISurface> surface, int x, int y, Direction facing);
        bool move();
        bool left();
        bool right();
        bool report(IReporter &reporter) const;

        bool is_placed() const { return m_surface != nullptr; }
        int x() const { return m_x; }
        int y() const { return m_y; }
        Direction facing() const { return m_facing; }

    protected:
        std::shared_ptr<ISurface> m_surface;
        int m_x;
        int m_y;
        Direction m_facing;
    };
}

#endif
