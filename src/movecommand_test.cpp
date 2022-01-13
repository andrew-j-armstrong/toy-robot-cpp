#include "movecommand.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

using namespace ToyRobot;
using namespace testing;

class MockRobot : public IRobot
{
public:
    MOCK_METHOD(bool, place, (std::shared_ptr<ISurface>, int, int, Direction), (override));
    MOCK_METHOD(bool, move, (), (override));
    MOCK_METHOD(bool, left, (), (override));
    MOCK_METHOD(bool, right, (), (override));
    MOCK_METHOD(bool, report, (IReporter &), (const override));
};

// Test that executing a move command will call move() on a robot and return successful if the move was successful
TEST(MoveCommandTest, ExecuteSuccessfulMove)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());

    EXPECT_CALL(*robot, move())
        .Times(1)
        .WillRepeatedly(Return(true));

    MoveCommand moveCommand(robot);

    EXPECT_EQ(true, moveCommand.execute());
}

// Test that executing a move command will call move() on a robot and return a failure if the move failed
TEST(MoveCommandTest, ExecuteFailedMove)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());

    EXPECT_CALL(*robot, move())
        .Times(1)
        .WillRepeatedly(Return(false));

    MoveCommand moveCommand(robot);

    EXPECT_EQ(false, moveCommand.execute());
}
