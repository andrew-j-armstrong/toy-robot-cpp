#include "commandfactory.h"

#include "movecommand.h"
#include "leftcommand.h"
#include "rightcommand.h"
#include "reportcommand.h"
#include "placecommand.h"
#include "exitcommand.h"

using namespace ToyRobot;

CommandFactory::CommandFactory(std::shared_ptr<IRobot> robot, std::shared_ptr<IReporter> reporter, std::shared_ptr<ISurface> surface)
: m_robot(move(robot))
, m_reporter(move(reporter))
, m_surface(move(surface))
{
}

CommandFactory::~CommandFactory()
{
}

std::unique_ptr<ICommand> CommandFactory::new_move_command() const
{
    return std::unique_ptr<ICommand>(new MoveCommand(m_robot));
}

std::unique_ptr<ICommand> CommandFactory::new_left_command() const
{
    return std::unique_ptr<ICommand>(new LeftCommand(m_robot));
}

std::unique_ptr<ICommand> CommandFactory::new_right_command() const
{
    return std::unique_ptr<ICommand>(new RightCommand(m_robot));
}

std::unique_ptr<ICommand> CommandFactory::new_report_command() const
{
    return std::unique_ptr<ICommand>(new ReportCommand(m_robot, m_reporter));
}

std::unique_ptr<ICommand> CommandFactory::new_place_command(int x, int y, Direction facing) const
{
    return std::unique_ptr<ICommand>(new PlaceCommand(m_robot, m_surface, x, y, facing));
}

std::unique_ptr<ICommand> CommandFactory::new_exit_command() const
{
    return std::unique_ptr<ICommand>(new ExitCommand());
}
