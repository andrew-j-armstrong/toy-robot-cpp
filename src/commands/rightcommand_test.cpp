#include "rightcommand.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

#include "../model/mockrobot.h"

using namespace ToyRobot;
using namespace testing;

// Test that executing a right command will call right() on a robot and return successful if the right was successful
TEST(RightCommandTest, ExecuteSuccessfulRight)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());

    EXPECT_CALL(*robot, right())
        .Times(1)
        .WillRepeatedly(Return(true));

    RightCommand rightCommand(robot);

    EXPECT_EQ(true, rightCommand.execute());
}

// Test that executing a right command will call right() on a robot and return a failure if the right failed
TEST(RightCommandTest, ExecuteFailedRight)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());

    EXPECT_CALL(*robot, right())
        .Times(1)
        .WillRepeatedly(Return(false));

    RightCommand rightCommand(robot);

    EXPECT_EQ(false, rightCommand.execute());
}

// Verify that an exception is thrown if an invalid robot is provided to the command
TEST(RightCommandTest, InvalidConstruction)
{
    EXPECT_THROW({
        try
        {
            RightCommand rightCommand(nullptr);
        }
        catch(const std::invalid_argument &e)
        {
            EXPECT_EQ(std::string("robot"), e.what());
            throw;
        }

    }, std::invalid_argument);
}
