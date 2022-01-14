#include "istreaminput.h"

#include <gmock/gmock.h>

using namespace ToyRobot;
using namespace testing;

// Tests that reporting works even for invalid locations
TEST(IStreamInputTest, TestReadLine)
{
    std::stringstream ss;
    std::string line;
    IStreamInput input(ss);

    ss.str("Hello World!\nThis is another line...\nThis is the end!");
    EXPECT_TRUE(input.read_line(line));
    EXPECT_EQ("Hello World!", line);
    EXPECT_TRUE(input.read_line(line));
    EXPECT_EQ("This is another line...", line);
    EXPECT_TRUE(input.read_line(line));
    EXPECT_EQ("This is the end!", line);
    EXPECT_FALSE(input.read_line(line));
}
