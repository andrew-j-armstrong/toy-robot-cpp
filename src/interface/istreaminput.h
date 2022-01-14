#ifndef TOYROBOT_ISTREAMINPUT_H_
#define TOYROBOT_ISTREAMINPUT_H_

#include <istream>
#include <string>

#include "iinput.h"

namespace ToyRobot
{
    class IStreamInput : public IInput
    {
    public:
        IStreamInput(std::istream &inputStream);
        virtual ~IStreamInput();

        bool read_line(std::string &line) override;

    private:
        std::istream &m_inputStream;
    };
}

#endif
