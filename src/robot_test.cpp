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

TEST(RobotTest, Move)
{
    std::shared_ptr<MockSurface> surface(new MockSurface());

    EXPECT_CALL(*surface, is_valid_location(_, _))
        .Times(1)
        .WillRepeatedly(Return(true));

    Robot robot(surface, 1, 1, North);
    EXPECT_EQ(true, robot.move());
    EXPECT_EQ(1, robot.x());
    EXPECT_EQ(2, robot.y());
}
