#ifndef TOYROBOT_OSTREAMREPORTER_H_
#define TOYROBOT_OSTREAMREPORTER_H_

#include <ostream>

#include "../model/ireporter.h"

namespace ToyRobot
{
    // OStreamReporter writes robot reports to a std::ostream (e.g. std::cout)
    class OStreamReporter : public IReporter
    {
    public:
        OStreamReporter(std::ostream &outputStream);
        ~OStreamReporter();

        void report(int x, int y, Direction facing) override;

    private:
        std::ostream &m_outputStream;
    };
}

#endif
