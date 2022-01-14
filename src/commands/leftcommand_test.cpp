#include "leftcommand.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

#include "../model/mockrobot.h"

using namespace ToyRobot;
using namespace testing;

// Test that executing a left command will call left() on a robot and return successful if the left was successful
TEST(LeftCommandTest, ExecuteSuccessfulLeft)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());

    EXPECT_CALL(*robot, left())
        .Times(1)
        .WillRepeatedly(Return(true));

    LeftCommand leftCommand(robot);

    EXPECT_TRUE(leftCommand.execute());
}

// Test that executing a left command will call left() on a robot and return a failure if the left failed
TEST(LeftCommandTest, ExecuteFailedLeft)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());

    EXPECT_CALL(*robot, left())
        .Times(1)
        .WillRepeatedly(Return(false));

    LeftCommand leftCommand(robot);

    EXPECT_FALSE(leftCommand.execute());
}

// Verify that an exception is thrown if an invalid robot is provided to the command
TEST(LeftCommandTest, InvalidConstruction)
{
    EXPECT_THROW({
        try
        {
            LeftCommand leftCommand(nullptr);
        }
        catch(const std::invalid_argument &e)
        {
            EXPECT_EQ(std::string("robot"), e.what());
            throw;
        }

    }, std::invalid_argument);
}
