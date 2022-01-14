#include "stringutil.h"

#include <gtest/gtest.h>

using namespace ToyRobot;

// Tests that to_lowercase converts uppercase characters to lowercase while ignoring other characters
TEST(StringUtilTest, ToLowercase)
{
    EXPECT_EQ("abc", to_lowercase("ABC"));
    EXPECT_EQ("abc123", to_lowercase("ABC123"));
    EXPECT_EQ("0a1b2c3", to_lowercase("0A1B2C3"));
    EXPECT_EQ("the quick brown fox jumped over the l@zy d0g.", to_lowercase("The Quick Brown Fox JUMPED over tHe l@zY d0g."));
}

// Tests that ltrim removes whitespace characters at the start of the string while ignoring all other characters (including trailing whitespace)
TEST(StringUtilTest, LTrim)
{
    EXPECT_EQ("ABC", ltrim(" ABC"));
    EXPECT_EQ("ABC123", ltrim("\t ABC123"));
    EXPECT_EQ("0A1B2C3\n\t", ltrim(" \n0A1B2C3\n\t"));
    EXPECT_EQ("The Quick Brown Fox JUMPED over tHe l@zY d0g.\r\n", ltrim("\tThe Quick Brown Fox JUMPED over tHe l@zY d0g.\r\n"));
}

// Tests that rtrim removes whitespace characters at the end of the string while ignoring all other characters (including leading whitespace)
TEST(StringUtilTest, RTrim)
{
    EXPECT_EQ("ABC", rtrim("ABC "));
    EXPECT_EQ("ABC123", rtrim("ABC123 \t"));
    EXPECT_EQ(" \n0A1B2C3", rtrim(" \n0A1B2C3\n\t"));
    EXPECT_EQ("\tThe Quick Brown Fox JUMPED over tHe l@zY d0g.", rtrim("\tThe Quick Brown Fox JUMPED over tHe l@zY d0g.\r\n"));
}

// Tests that trim removes whitespace characters at the start and end of the string while ignoring all other characters
TEST(StringUtilTest, Trim)
{
    EXPECT_EQ("ABC", trim("ABC "));
    EXPECT_EQ("ABC123", trim("\t ABC123"));
    EXPECT_EQ("0A1B2C3", trim(" \n0A1B2C3\r\n"));
    EXPECT_EQ("The Quick Brown Fox JUMPED over tHe l@zY d0g.", trim("\tThe Quick Brown Fox JUMPED over tHe l@zY d0g.\r\n"));
}
