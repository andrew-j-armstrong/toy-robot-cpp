#include "ostreamreporter.h"

#include <gtest/gtest.h>
#include <sstream>

using namespace ToyRobot;

// Tests that reporting works for each direction
TEST(OStreamReporterTest, AllDirections)
{
    std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(2,2,North);
    EXPECT_EQ("2,2,North\n", ss.str());

    ss.str("");
    reporter.report(2,2,East);
    EXPECT_EQ("2,2,East\n", ss.str());

    ss.str("");
    reporter.report(2,2,South);
    EXPECT_EQ("2,2,South\n", ss.str());

    ss.str("");
    reporter.report(2,2,West);
    EXPECT_EQ("2,2,West\n", ss.str());
}

// Tests that reporting works even for invalid locations
TEST(OStreamReporterTest, UnknownDirection)
{
   std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(-1,-1,UnknownDirection);
    EXPECT_EQ("-1,-1,<Unknown>\n", ss.str());
}

// Tests that reporting works for locations at the edges of the table
TEST(OStreamReporterTest, LimitLocations)
{
    std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(0,0,South);
    EXPECT_EQ("0,0,South\n", ss.str());

    ss.str("");
    reporter.report(0,4,West);
    EXPECT_EQ("0,4,West\n", ss.str());

    ss.str("");
    reporter.report(4,4,North);
    EXPECT_EQ("4,4,North\n", ss.str());

    ss.str("");
    reporter.report(4,0,East);
    EXPECT_EQ("4,0,East\n", ss.str());
}

// Tests that reporting still works for locations outside the expected table size
TEST(OStreamReporterTest, OffTable)
{
   std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(-1,-1,North);
    EXPECT_EQ("-1,-1,North\n", ss.str());

    ss.str("");
    reporter.report(5,5,South);
    EXPECT_EQ("5,5,South\n", ss.str());
}
