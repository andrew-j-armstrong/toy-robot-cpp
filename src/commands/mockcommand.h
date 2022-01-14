#ifndef TOYROBOT_MOCKCOMMAND_H_
#define TOYROBOT_MOCKCOMMAND_H_

#include <gmock/gmock.h>

#include "icommand.h"

namespace ToyRobot
{
    // Mock command factory for testing
    class MockCommand : public ICommand
    {
    public:
        MOCK_METHOD(bool, execute, (), (const override));
    };
}

#endif
