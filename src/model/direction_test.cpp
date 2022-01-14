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

// Test that each direction is correctly converted to a string
TEST(DirectionTest, FromStringAllDirections)
{
    EXPECT_EQ(North, from_string("North"));
    EXPECT_EQ(East, from_string(" east"));
    EXPECT_EQ(South, from_string("SOUTH "));
    EXPECT_EQ(West, from_string("\t weST "));
}

// Test that invalid directions produce an <Unknown> string
TEST(DirectionTest, FromStringUnknownDirections)
{
    EXPECT_EQ(UnknownDirection, from_string("Blah"));
    EXPECT_EQ(UnknownDirection, from_string(""));
    EXPECT_EQ(UnknownDirection, from_string("North1"));
    EXPECT_EQ(UnknownDirection, from_string("-"));
    EXPECT_EQ(UnknownDirection, from_string("northsouth"));
    EXPECT_EQ(UnknownDirection, from_string("innorth"));
}

// Test that valid directions are correctly identified
TEST(DirectionTest, IsValidDirection)
{
    EXPECT_TRUE(is_valid_direction(North));
    EXPECT_TRUE(is_valid_direction(East));
    EXPECT_TRUE(is_valid_direction(South));
    EXPECT_TRUE(is_valid_direction(West));
}

// Test that invalid directions are correctly identified
TEST(DirectionTest, IsInvalidDirection)
{
    EXPECT_FALSE(is_valid_direction(UnknownDirection));
    EXPECT_FALSE(is_valid_direction((Direction)(MinDirection - 1)));
    EXPECT_FALSE(is_valid_direction((Direction)(MaxDirection + 1)));
}
