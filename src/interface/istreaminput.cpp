#include "istreaminput.h"

using namespace ToyRobot;

IStreamInput::IStreamInput(std::istream &inputStream)
: m_inputStream(inputStream)
{
}

IStreamInput::~IStreamInput()
{
}

bool IStreamInput::read_line(std::string &line)
{
    if (m_inputStream.eof())
        return false;

    std::getline(m_inputStream, line);
    return true;
}
