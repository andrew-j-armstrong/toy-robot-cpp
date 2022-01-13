#include "ostreamreporter.h"

using namespace ToyRobot;

OStreamReporter::OStreamReporter(std::ostream &outputStream)
: m_outputStream(outputStream)
{
}

OStreamReporter::~OStreamReporter()
{
}

void OStreamReporter::report(int x, int y, Direction facing)
{
    m_outputStream << x << "," << y << "," << to_string(facing) << std::endl;
}
