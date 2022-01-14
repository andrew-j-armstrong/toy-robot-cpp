#ifndef TOYROBOT_MOCKROBOT_H_
#define TOYROBOT_MOCKROBOT_H_

#include <gmock/gmock.h>

#include "irobot.h"

namespace ToyRobot
{
    // Mock robot used in many tests
    class MockRobot : public IRobot
    {
    public:
        MOCK_METHOD(bool, place, (std::shared_ptr<ISurface>, int, int, Direction), (override));
        MOCK_METHOD(bool, move, (), (override));
        MOCK_METHOD(bool, left, (), (override));
        MOCK_METHOD(bool, right, (), (override));
        MOCK_METHOD(bool, report, (IReporter &), (const override));
    };
}

#endif
