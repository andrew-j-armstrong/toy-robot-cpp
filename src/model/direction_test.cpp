#include "direction.h"

#include <gtest/gtest.h>
#include <sstream>

using namespace ToyRobot;

// Test that each direction is correctly converted to a string
TEST(DirectionTest, AllDirections)
{
    EXPECT_EQ("North", to_string(North));
    EXPECT_EQ("East", to_string(East));
    EXPECT_EQ("South", to_string(South));
    EXPECT_EQ("West", to_string(West));
}

// Test that invalid directions produce an <Unknown> string
TEST(DirectionTest, UnknownDirections)
{
    EXPECT_EQ("<Unknown>", to_string(UnknownDirection));
    EXPECT_EQ("<Unknown>", to_string((Direction)(MaxDirection+1)));
}
