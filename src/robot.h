#ifndef TOYROBOT_ROBOT_H_
#define TOYROBOT_ROBOT_H_

#include <memory>

#include "irobot.h"
#include "direction.h"
#include "isurface.h"
#include "ireporter.h"

namespace ToyRobot
{
    // Robot encapsulates the toy robot in our model, and can be manipulated through the actions defined in the problem.
    class Robot : public IRobot
    {
    public:
        Robot();
        Robot(std::shared_ptr<ISurface> surface, int x, int y, Direction facing);
        virtual ~Robot();

        bool place(std::shared_ptr<ISurface> surface, int x, int y, Direction facing) override;
        bool move() override;
        bool left() override;
        bool right() override;
        bool report(IReporter &reporter) const override;

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
