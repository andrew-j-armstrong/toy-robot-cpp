#include "commandfactory.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ToyRobot;
using namespace testing;

#include "../model/mockreporter.h"
#include "../model/mockrobot.h"
#include "../model/mocksurface.h"

// Test that executing a left command will call left() on a robot and return successful if the left was successful
TEST(CommandFactoryTest, NewCommands)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());
    std::shared_ptr<MockSurface> surface(new MockSurface());
    std::shared_ptr<MockReporter> reporter(new MockReporter());

    CommandFactory commandFactory(robot, reporter, surface);

    // You could test the result types through dynamic_cast<>(), but this seems excessive coupling to implementation rather than behaviour
    EXPECT_TRUE(commandFactory.new_move_command());
    EXPECT_TRUE(commandFactory.new_left_command());
    EXPECT_TRUE(commandFactory.new_right_command());
    EXPECT_TRUE(commandFactory.new_report_command());
    EXPECT_TRUE(commandFactory.new_exit_command());
    EXPECT_TRUE(commandFactory.new_place_command(1, 2, North));
}
