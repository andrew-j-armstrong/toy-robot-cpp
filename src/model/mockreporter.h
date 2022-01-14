#ifndef TOYROBOT_MOCKREPORTER_H_
#define TOYROBOT_MOCKREPORTER_H_

#include <gmock/gmock.h>

#include "ireporter.h"

namespace ToyRobot
{
    class MockReporter : public IReporter
    {
    public:
        MOCK_METHOD(void, report, (int, int, Direction), (override));
    };
}

#endif
