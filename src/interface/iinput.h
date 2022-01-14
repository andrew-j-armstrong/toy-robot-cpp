#ifndef TOYROBOT_IINPUT_H_
#define TOYROBOT_IINPUT_H_

#include <string>

namespace ToyRobot
{
    class IInput
    {
    public:
        virtual ~IInput() {}

        virtual bool read_line(std::string &line) = 0;

    protected:
        IInput() {}
    };
}

#endif
