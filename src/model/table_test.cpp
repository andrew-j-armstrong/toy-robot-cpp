#include "table.h"

#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace ToyRobot;

// Test that the table can be constructed with a valid width and height
TEST(TableTest, TableConstruction)
{
    Table table(4, 6);

    EXPECT_EQ(4, table.width());
    EXPECT_EQ(6, table.height());
}

// Test that the table can be constructed with a valid width and height
TEST(TableTest, InvalidTableConstruction)
{
    EXPECT_THROW({Table table(0, 0);}, std::invalid_argument);
    EXPECT_THROW({Table table(-1, -1);}, std::invalid_argument);

    EXPECT_THROW({
        try
        {
            Table table(0, 5);
        }
        catch(const std::invalid_argument &e)
        {
            EXPECT_EQ(std::string("width"), e.what());
            throw;
        }

    }, std::invalid_argument);
    
    EXPECT_THROW({
        try
        {
            Table table(5, 0);
        }
        catch(const std::invalid_argument &e)
        {
            EXPECT_EQ(std::string("height"), e.what());
            throw;
        }

    }, std::invalid_argument);
}

// Test that valid locations on the table are correctly identified
TEST(TableTest, CheckValidLocations)
{
    {
        Table table(5, 5);

        EXPECT_TRUE(table.is_valid_location(0, 0));
        EXPECT_TRUE(table.is_valid_location(2, 2));
        EXPECT_TRUE(table.is_valid_location(0, 4));
        EXPECT_TRUE(table.is_valid_location(4, 4));
        EXPECT_TRUE(table.is_valid_location(4, 0));
    }

    {
        Table table(8, 8);

        EXPECT_TRUE(table.is_valid_location(0, 0));
        EXPECT_TRUE(table.is_valid_location(4, 4));
        EXPECT_TRUE(table.is_valid_location(0, 7));
        EXPECT_TRUE(table.is_valid_location(7, 7));
        EXPECT_TRUE(table.is_valid_location(7, 0));
    }
}

// Test that invalid locations on the table are correctly identified
TEST(TableTest, CheckInvalidLocations)
{
    {
        Table table(5, 5);

        EXPECT_FALSE(table.is_valid_location(-1, 0));
        EXPECT_FALSE(table.is_valid_location(0, 5));
        EXPECT_FALSE(table.is_valid_location(5, 4));
        EXPECT_FALSE(table.is_valid_location(4, -1));
    }

    {
        Table table(8, 8);

        EXPECT_FALSE(table.is_valid_location(-1, 0));
        EXPECT_FALSE(table.is_valid_location(0, 8));
        EXPECT_FALSE(table.is_valid_location(8, 4));
        EXPECT_FALSE(table.is_valid_location(4, -1));
    }
}
