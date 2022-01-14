#ifndef TOYROBOT_SIMULATION_H_
#define TOYROBOT_SIMULATION_H_

#include "interface/iinput.h"
#include "parser/itextparser.h"

namespace ToyRobot
{
    void run_simulation(std::shared_ptr<IInput> input, std::shared_ptr<ITextParser> parser);
}

#endif
