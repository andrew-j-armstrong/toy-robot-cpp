#ifndef TOYROBOT_IREPORTER_H_
#define TOYROBOT_IREPORTER_H_

#include "direction.h"

namespace ToyRobot
{
    class IReporter
    {
    public:
        virtual ~IReporter() {}

        virtual void report(int x, int y, Direction facing) = 0;

    protected:
        IReporter() {}
        
    };
}

#endif
