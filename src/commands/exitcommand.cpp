#include "exitcommand.h"

#include <stdexcept>

using namespace ToyRobot;

ExitCommand::ExitCommand()
{
}

ExitCommand::~ExitCommand()
{
}

bool ExitCommand::execute() const
{
    std::exit(0);
}
