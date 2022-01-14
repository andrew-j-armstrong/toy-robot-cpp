#include "placecommand.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

#include "../model/mockrobot.h"
#include "../model/mocksurface.h"

using namespace ToyRobot;
using namespace testing;

// Test that executing a place command will call place() on a robot and return successful if the place was successful
TEST(PlaceCommandTest, ExecuteSuccessfulPlace)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*robot, place(_, 2, 2, North))
        .Times(1)
        .WillRepeatedly(Return(true));

    PlaceCommand placeCommand(robot, surface, 2, 2, North);

    EXPECT_TRUE(placeCommand.execute());
}

// Test that executing a place command will call place() on a robot and return a failure if the place action fails
TEST(PlaceCommandTest, ExecuteFailedPlace)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*robot, place(_, 0, 0, South))
        .Times(1)
        .WillRepeatedly(Return(false));

    PlaceCommand placeCommand(robot, surface, 0, 0, South);

    EXPECT_FALSE(placeCommand.execute());
}

// Verify that an exception is thrown if an invalid robot or surface is provided to the command
TEST(PlaceCommandTest, InvalidConstruction)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_THROW({
        try
        {
            PlaceCommand placeCommand(nullptr, surface, 0, 0, South);
        }
        catch(const std::invalid_argument &e)
        {
            EXPECT_EQ(std::string("robot"), e.what());
            throw;
        }

    }, std::invalid_argument);

    EXPECT_THROW({
        try
        {
            PlaceCommand placeCommand(robot, nullptr, 0, 0, South);
        }
        catch(const std::invalid_argument &e)
        {
            EXPECT_EQ(std::string("surface"), e.what());
            throw;
        }

    }, std::invalid_argument);

    EXPECT_THROW({ PlaceCommand placeCommand(nullptr, nullptr, 0, 0, South); }, std::invalid_argument);
}
