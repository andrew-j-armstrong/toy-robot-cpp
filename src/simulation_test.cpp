#include "simulation.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "interface/iinput.h"
#include "parser/itextparser.h"
#include "commands/mockcommand.h"

using namespace ToyRobot;
using namespace testing;

class MockInput : public IInput
{
public:
    MOCK_METHOD(bool, read_line, (std::string &), (override));
};

class MockTextParser : public ITextParser
{
public:
    MOCK_METHOD(std::unique_ptr<ICommand>, parse_command, (const std::string &), (const override));
};

// Tests that run_simulation() will continue until read_line returns false, and parse_command will be called for each successful read_line.
TEST(SimulationTest, BasicSimulation)
{
    MockInput input;
    MockTextParser parser;

    EXPECT_CALL(input, read_line(_))
        .Times(4)
        .WillOnce(Return(true))
        .WillOnce(Return(true))
        .WillOnce(Return(true))
        .WillOnce(Return(false));

    // Due to returning a unique_ptr, need to use WillOnce(Return(ByMove())) for each call rather than WillRepeatedly() as ByMove can only be called once for each instance
    EXPECT_CALL(parser, parse_command(_))
        .Times(3)
        .WillOnce(Return(ByMove(nullptr)))
        .WillOnce(Return(ByMove(nullptr)))
        .WillOnce(Return(ByMove(nullptr)));

    run_simulation(input, parser);
}

// Tests that if read_line is succesful, and parse_command returns a valid command, that that command's execute() function will be called.
TEST(SimulationTest, ValidCommand)
{
    MockInput input;
    MockTextParser parser;
    std::unique_ptr<MockCommand> command(new MockCommand());

    EXPECT_CALL(input, read_line(_))
        .Times(2)
        .WillOnce(Return(true))
        .WillOnce(Return(false));

    EXPECT_CALL(*command, execute()).Times(1);

    EXPECT_CALL(parser, parse_command(_))
        .Times(1)
        .WillOnce(Return(ByMove(move(command))));

    run_simulation(input, parser);
}
