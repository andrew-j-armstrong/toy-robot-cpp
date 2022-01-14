#include "reportcommand.h"

#include <stdexcept>

using namespace ToyRobot;

ReportCommand::ReportCommand(std::shared_ptr<IRobot> robot, std::shared_ptr<IReporter> reporter)
: m_robot(std::move(robot))
, m_reporter(std::move(reporter))
{
    if (!m_robot)
        throw std::invalid_argument("robot");
    if (!m_reporter)
        throw std::invalid_argument("reporter");
}

ReportCommand::~ReportCommand()
{
}

bool ReportCommand::execute() const
{
    return m_robot->report(*m_reporter);
}
