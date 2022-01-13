#include "robot.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include <memory>

#include "isurface.h"

using namespace ToyRobot;
using namespace testing;

class MockSurface : public ISurface
{
public:
    MOCK_METHOD(bool, is_valid_location, (int, int), (override));
};

// Tests the robot moving correctly in each direction
TEST(RobotTest, MoveAllDirections)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(4)
        .WillRepeatedly(Return(true));

    // Using new robots for each test to avoid this test being dependent on place()
    {
        Robot robot(surface, 2, 2, North);
        EXPECT_EQ(true, robot.move());
        EXPECT_EQ(2, robot.x());
        EXPECT_EQ(3, robot.y());
        EXPECT_EQ(North, robot.facing());
    }

    {
        Robot robot(surface, 2, 2, East);
        EXPECT_EQ(true, robot.move());
        EXPECT_EQ(3, robot.x());
        EXPECT_EQ(2, robot.y());
        EXPECT_EQ(East, robot.facing());
    }

    {
        Robot robot(surface, 2, 2, South);
        EXPECT_EQ(true, robot.move());
        EXPECT_EQ(2, robot.x());
        EXPECT_EQ(1, robot.y());
        EXPECT_EQ(South, robot.facing());
    }

    {
        Robot robot(surface, 2, 2, West);
        EXPECT_EQ(true, robot.move());
        EXPECT_EQ(1, robot.x());
        EXPECT_EQ(2, robot.y());
        EXPECT_EQ(West, robot.facing());
    }
}

// Tests that the robot will ignore the move command if its facing is invalid
TEST(RobotTest, MoveInvalidDirection)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(0);

    Robot robot(surface, 2, 2, UnknownDirection);
    EXPECT_EQ(false, robot.move());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(UnknownDirection, robot.facing());
}

// Tests that the robot will not move if it is requested to move to an invalid location
TEST(RobotTest, MoveInvalidLocation)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(1)
        .WillRepeatedly(Return(false));

    Robot robot(surface, 2, 2, North);
    EXPECT_EQ(false, robot.move());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
}

// Tests that the robot will correctly turn left around all directions
TEST(RobotTest, LeftAllDirections)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(0);

    Robot robot(surface, 2, 2, North);

    EXPECT_EQ(true, robot.left());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(West, robot.facing());

    EXPECT_EQ(true, robot.left());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(South, robot.facing());

    EXPECT_EQ(true, robot.left());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(East, robot.facing());

    EXPECT_EQ(true, robot.left());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(North, robot.facing());
}

// Tests that the robot will ignore a left command if it's not placed
TEST(RobotTest, LeftNotPlaced)
{
    Robot robot(nullptr, 2, 2, North);

    EXPECT_EQ(false, robot.left());
    EXPECT_EQ(false, robot.is_placed());
}

// Tests that the robot will ignore a left command if its direction is invalid
TEST(RobotTest, LeftInvalidDirection)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(0);

    Robot robot(surface, 2, 2, UnknownDirection);

    EXPECT_EQ(false, robot.left());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(UnknownDirection, robot.facing());
}

// Tests that the robot will correctly turn right around all directions
TEST(RobotTest, RightAllDirections)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(0);

    Robot robot(surface, 2, 2, North);

    EXPECT_EQ(true, robot.right());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(East, robot.facing());

    EXPECT_EQ(true, robot.right());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(South, robot.facing());

    EXPECT_EQ(true, robot.right());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(West, robot.facing());

    EXPECT_EQ(true, robot.right());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(North, robot.facing());
}

// Tests that the robot will ignore a right command if it's not placed
TEST(RobotTest, RightNotPlaced)
{
    Robot robot(nullptr, 2, 2, North);

    EXPECT_EQ(false, robot.right());
    EXPECT_EQ(false, robot.is_placed());
}

// Tests that the robot will ignore a right command if its direction is invalid
TEST(RobotTest, RightInvalidDirection)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(0);

    Robot robot(surface, 2, 2, UnknownDirection);

    EXPECT_EQ(false, robot.right());
    EXPECT_EQ(2, robot.x());
    EXPECT_EQ(2, robot.y());
    EXPECT_EQ(UnknownDirection, robot.facing());
}
