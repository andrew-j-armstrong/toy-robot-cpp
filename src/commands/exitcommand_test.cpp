#include "exitcommand.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace ToyRobot;
using namespace testing;

// Verify that the exit command will terminate the application
TEST(ExitCommandTest, VerifyExit)
{
    ExitCommand exitCommand;

    EXPECT_EXIT(exitCommand.execute(), testing::ExitedWithCode(0), "");
}
