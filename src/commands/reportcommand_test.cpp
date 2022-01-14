#include "reportcommand.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>

#include "../model/mockrobot.h"
#include "../model/mockreporter.h"

using namespace ToyRobot;
using namespace testing;

// Test that executing a report command will call report() on a robot and return successful if the report was successful
TEST(ReportCommandTest, ExecuteSuccessfulReport)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());
    std::shared_ptr<MockReporter> reporter(new MockReporter());

    EXPECT_CALL(*robot, report(_))
        .Times(1)
        .WillRepeatedly(Return(true));

    ReportCommand reportCommand(robot, reporter);

    EXPECT_EQ(true, reportCommand.execute());
}

// Test that executing a report  command will call report() on a robot and return a failure if the report failed
TEST(ReportCommandTest, ExecuteFailedReport)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());
    std::shared_ptr<MockReporter> reporter(new MockReporter());

    EXPECT_CALL(*robot, report(_))
        .Times(1)
        .WillRepeatedly(Return(false));

    ReportCommand reportCommand(robot, reporter);

    EXPECT_EQ(false, reportCommand.execute());
}
