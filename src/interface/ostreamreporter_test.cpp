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
    reporter.report(2, 2, North);
    EXPECT_EQ("2,2,NORTH\n", ss.str());

    ss.str("");
    reporter.report(2, 2, East);
    EXPECT_EQ("2,2,EAST\n", ss.str());

    ss.str("");
    reporter.report(2, 2, South);
    EXPECT_EQ("2,2,SOUTH\n", ss.str());

    ss.str("");
    reporter.report(2, 2, West);
    EXPECT_EQ("2,2,WEST\n", ss.str());
}

// Tests that reporting works even for invalid locations
TEST(OStreamReporterTest, InvalidDirection)
{
    std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(-1, -1, UnknownDirection);
    EXPECT_EQ("-1,-1,<Unknown>\n", ss.str());
}

// Tests that reporting works for locations at the edges of the table
TEST(OStreamReporterTest, LimitLocations)
{
    std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(0, 0, South);
    EXPECT_EQ("0,0,SOUTH\n", ss.str());

    ss.str("");
    reporter.report(0, 4, West);
    EXPECT_EQ("0,4,WEST\n", ss.str());

    ss.str("");
    reporter.report(4, 4, North);
    EXPECT_EQ("4,4,NORTH\n", ss.str());

    ss.str("");
    reporter.report(4, 0, East);
    EXPECT_EQ("4,0,EAST\n", ss.str());
}

// Tests that reporting still works for locations outside the expected table size
TEST(OStreamReporterTest, OffTable)
{
   std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(-1,-1,North);
    EXPECT_EQ("-1,-1,NORTH\n", ss.str());

    ss.str("");
    reporter.report(5,5,South);
    EXPECT_EQ("5,5,SOUTH\n", ss.str());
}
