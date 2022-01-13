#include "ostreamreporter.h"

#include <gtest/gtest.h>
#include <sstream>

using namespace ToyRobot;

TEST(OStreamReporterTest, AllDirections)
{
    std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(1,1,North);
    EXPECT_EQ("1,1,North\n", ss.str());

    ss.str("");
    reporter.report(1,1,East);
    EXPECT_EQ("1,1,East\n", ss.str());

    ss.str("");
    reporter.report(1,1,South);
    EXPECT_EQ("1,1,South\n", ss.str());

    ss.str("");
    reporter.report(1,1,West);
    EXPECT_EQ("1,1,West\n", ss.str());
}

TEST(OStreamReporterTest, UnknownDirection)
{
   std::stringstream ss;
    OStreamReporter reporter(ss);

    ss.str("");
    reporter.report(-1,-1,Unknown);
    EXPECT_EQ("-1,-1,<Unknown>\n", ss.str());
}

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
