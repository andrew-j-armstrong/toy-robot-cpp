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

    EXPECT_TRUE(reportCommand.execute());
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

    EXPECT_FALSE(reportCommand.execute());
}

// Verify that an exception is thrown if an invalid robot or reporter is provided to the command
TEST(ReportCommandTest, InvalidConstruction)
{
    std::shared_ptr<MockRobot> robot(new MockRobot());
    std::shared_ptr<MockReporter> reporter(new MockReporter());

    EXPECT_THROW({
        try
        {
            ReportCommand reportCommand(nullptr, reporter);
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
            ReportCommand reportCommand(robot, nullptr);
        }
        catch(const std::invalid_argument &e)
        {
            EXPECT_EQ(std::string("reporter"), e.what());
            throw;
        }

    }, std::invalid_argument);

    EXPECT_THROW({ ReportCommand reportCommand(nullptr, nullptr); }, std::invalid_argument);
}
