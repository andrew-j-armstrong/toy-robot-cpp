#ifndef TOYROBOT_MOCKCOMMANDFACTORY_H_
#define TOYROBOT_MOCKCOMMANDFACTORY_H_

#include <gmock/gmock.h>

#include "icommandfactory.h"

namespace ToyRobot
{
    // Mock command factory for testing
    class MockCommandFactory : public ICommandFactory
    {
    public:
        MOCK_METHOD(std::unique_ptr<ICommand>, new_move_command, (), (const override));
        MOCK_METHOD(std::unique_ptr<ICommand>, new_left_command, (), (const override));
        MOCK_METHOD(std::unique_ptr<ICommand>, new_right_command, (), (const override));
        MOCK_METHOD(std::unique_ptr<ICommand>, new_report_command, (), (const override));
        MOCK_METHOD(std::unique_ptr<ICommand>, new_place_command, (int, int, Direction), (const override));
    };
}

#endif
