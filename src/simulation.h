#ifndef TOYROBOT_SIMULATION_H_
#define TOYROBOT_SIMULATION_H_

#include "interface/iinput.h"
#include "parser/itextparser.h"

namespace ToyRobot
{
    // Runs the Toy Robot simulation, reading lines from input and parsing them using the parser to get commands, and executing all valid commands
    void run_simulation(IInput &input, const ITextParser &parser);
}

#endif
