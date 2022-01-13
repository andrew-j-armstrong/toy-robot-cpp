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
    }

    {
        Robot robot(surface, 2, 2, East);
        EXPECT_EQ(true, robot.move());
        EXPECT_EQ(3, robot.x());
        EXPECT_EQ(2, robot.y());
    }

    {
        Robot robot(surface, 2, 2, South);
        EXPECT_EQ(true, robot.move());
        EXPECT_EQ(2, robot.x());
        EXPECT_EQ(1, robot.y());
    }

    {
        Robot robot(surface, 2, 2, West);
        EXPECT_EQ(true, robot.move());
        EXPECT_EQ(1, robot.x());
        EXPECT_EQ(2, robot.y());
    }
}

// Tests that the robot will ignore the move command if its facing is invalid
TEST(RobotTest, MoveInvalidDirection)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(0);

    Robot robot1(surface, 2, 2, UnknownDirection);
    EXPECT_EQ(false, robot1.move());
    EXPECT_EQ(2, robot1.x());
    EXPECT_EQ(2, robot1.y());
}

// Tests that the robot will not move if it is requested to move to an invalid location
TEST(RobotTest, MoveInvalidLocation)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(1)
        .WillRepeatedly(Return(false));

    Robot robot1(surface, 2, 2, North);
    EXPECT_EQ(false, robot1.move());
    EXPECT_EQ(2, robot1.x());
    EXPECT_EQ(2, robot1.y());
}
