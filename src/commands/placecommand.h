#ifndef TOYROBOT_PLACECOMMAND_H_
#define TOYROBOT_PLACECOMMAND_H_

#include <memory>

#include "icommand.h"
#include "../model/irobot.h"

namespace ToyRobot
{
    class PlaceCommand : public ICommand
    {
    public:
        // The constructor of PlaceCommand can throw an exception if the robot or surface are invalid
        PlaceCommand(std::shared_ptr<IRobot> robot, std::shared_ptr<ISurface> surface, int x, int y, Direction facing);
        virtual ~PlaceCommand();

        bool execute() const override;

    protected:
        std::shared_ptr<IRobot> m_robot;
        std::shared_ptr<ISurface> m_surface;
        int m_x;
        int m_y;
        Direction m_facing;
    };
}

#endif
