#include "direction.h"

#include <gtest/gtest.h>
#include <sstream>

using namespace ToyRobot;

// Test that each direction is correctly converted to a string
TEST(DirectionTest, ToStringAllDirections)
{
    EXPECT_EQ("North", to_string(North));
    EXPECT_EQ("East", to_string(East));
    EXPECT_EQ("South", to_string(South));
    EXPECT_EQ("West", to_string(West));
}

// Test that invalid directions produce an <Unknown> string
TEST(DirectionTest, ToStringUnknownDirections)
{
    EXPECT_EQ("<Unknown>", to_string(UnknownDirection));
    EXPECT_EQ("<Unknown>", to_string((Direction)(MinDirection - 1)));
    EXPECT_EQ("<Unknown>", to_string((Direction)(MaxDirection + 1)));
}

// Test that valid directions are correctly identified
TEST(DirectionTest, IsValidDirection)
{
    EXPECT_EQ(true, is_valid_direction(North));
    EXPECT_EQ(true, is_valid_direction(East));
    EXPECT_EQ(true, is_valid_direction(South));
    EXPECT_EQ(true, is_valid_direction(West));
}

// Test that invalid directions are correctly identified
TEST(DirectionTest, IsInvalidDirection)
{
    EXPECT_EQ(false, is_valid_direction(UnknownDirection));
    EXPECT_EQ(false, is_valid_direction((Direction)(MinDirection - 1)));
    EXPECT_EQ(false, is_valid_direction((Direction)(MaxDirection + 1)));
}
