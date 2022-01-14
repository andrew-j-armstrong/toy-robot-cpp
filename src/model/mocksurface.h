#ifndef TOYROBOT_MOCKSURFACE_H_
#define TOYROBOT_MOCKSURFACE_H_

#include <gmock/gmock.h>

#include "isurface.h"

namespace ToyRobot
{
    // Mock surface used in many tests
    class MockSurface : public ISurface
    {
    public:
        MOCK_METHOD(bool, is_valid_location, (int, int), (const override));
    };
}

#endif
