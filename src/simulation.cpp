#include "simulation.h"

using namespace ToyRobot;

void ToyRobot::run_simulation(IInput &input, const ITextParser &parser)
{
    std::string line;
    while(input.read_line(line))
    {
        auto command = parser.parse_command(line);
        if (command)
            command->execute();
    }
}
