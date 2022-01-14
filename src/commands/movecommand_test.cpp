#include "movecommand.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

#include "../model/mockrobot.h"

using namespace ToyRobot;
using namespace testing;

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

// Verify that an exception is thrown if an invalid robot is provided to the command
TEST(MoveCommandTest, InvalidConstruction)
{
    EXPECT_THROW({
        try
        {
            MoveCommand moveCommand(nullptr);
        }
        catch(const std::invalid_argument &e)
        {
            EXPECT_EQ(std::string("robot"), e.what());
            throw;
        }

    }, std::invalid_argument);
}
