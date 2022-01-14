#include "textparser.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../commands/mockcommandfactory.h"
#include "../commands/mockcommand.h"

using namespace ToyRobot;
using namespace testing;

// Test parsing move command
TEST(TextParserTest, ValidMoveCommand)
{
    TextParser parser;
    MockCommandFactory commandFactory;
    
    EXPECT_CALL(commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_CALL(commandFactory, new_move_command())
        .Times(4)
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("move", commandFactory));
    EXPECT_TRUE(parser.parse_command(" Move", commandFactory));
    EXPECT_TRUE(parser.parse_command("MOVE ", commandFactory));
    EXPECT_TRUE(parser.parse_command("\t MOve ", commandFactory));
}

// Test parsing left command
TEST(TextParserTest, ValidLeftCommand)
{
    TextParser parser;
    MockCommandFactory commandFactory;
    
    EXPECT_CALL(commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_CALL(commandFactory, new_left_command())
        .Times(4)
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("left", commandFactory));
    EXPECT_TRUE(parser.parse_command(" Left", commandFactory));
    EXPECT_TRUE(parser.parse_command("LEFT ", commandFactory));
    EXPECT_TRUE(parser.parse_command("\t LEft ", commandFactory));
}

// Test parsing right command
TEST(TextParserTest, ValidRightCommand)
{
    TextParser parser;
    MockCommandFactory commandFactory;
    
    EXPECT_CALL(commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_CALL(commandFactory, new_right_command())
        .Times(4)
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("right", commandFactory));
    EXPECT_TRUE(parser.parse_command(" Right", commandFactory));
    EXPECT_TRUE(parser.parse_command("RIGHT ", commandFactory));
    EXPECT_TRUE(parser.parse_command("\t RIght ", commandFactory));
}

// Test parsing report command
TEST(TextParserTest, ValidReportCommand)
{
    TextParser parser;
    MockCommandFactory commandFactory;
    
    EXPECT_CALL(commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_CALL(commandFactory, new_report_command())
        .Times(4)
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("report", commandFactory));
    EXPECT_TRUE(parser.parse_command(" Report", commandFactory));
    EXPECT_TRUE(parser.parse_command("REPORT ", commandFactory));
    EXPECT_TRUE(parser.parse_command("\t REport ", commandFactory));
}

// Test parsing place command
TEST(TextParserTest, ValidPlaceCommand)
{
    TextParser parser;
    MockCommandFactory commandFactory;
    
    EXPECT_CALL(commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(commandFactory, new_report_command()).Times(0);

    EXPECT_CALL(commandFactory, new_place_command(1, 2, North)).Times(1).WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));
    EXPECT_CALL(commandFactory, new_place_command(0, 0, South)).Times(1).WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));
    EXPECT_CALL(commandFactory, new_place_command(-1, -2, West)).Times(1).WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));
    EXPECT_CALL(commandFactory, new_place_command(15, 15, East)).Times(1).WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("place 1,2,north", commandFactory));
    EXPECT_TRUE(parser.parse_command(" Place 0, 0, South", commandFactory));
    EXPECT_TRUE(parser.parse_command("PLACE -1 , -2 , WEST", commandFactory));
    EXPECT_TRUE(parser.parse_command("\t pLAce 15,15, eASt \n", commandFactory));
}

// Test parsing place commands with invalid parameters
TEST(TextParserTest, InvalidPlaceCommand)
{
    TextParser parser;
    MockCommandFactory commandFactory;
    
    EXPECT_CALL(commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_FALSE(parser.parse_command("place 1 2 north", commandFactory));
    EXPECT_FALSE(parser.parse_command("place 1,2", commandFactory));
    EXPECT_FALSE(parser.parse_command("place 1,2,nort", commandFactory));
    EXPECT_FALSE(parser.parse_command("place ,,", commandFactory));
    EXPECT_FALSE(parser.parse_command("place 0,,north", commandFactory));
    EXPECT_FALSE(parser.parse_command("place ,0,north", commandFactory));
    EXPECT_FALSE(parser.parse_command("place 1,2,,north", commandFactory));
}

// Test invalid commands similar to valid commands
TEST(TextParserTest, InvalidCommand)
{
    TextParser parser;
    MockCommandFactory commandFactory;
    
    EXPECT_CALL(commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_FALSE(parser.parse_command("blah", commandFactory));
    EXPECT_FALSE(parser.parse_command("movey", commandFactory));
    EXPECT_FALSE(parser.parse_command("1left", commandFactory));
    EXPECT_FALSE(parser.parse_command("right right", commandFactory));
    EXPECT_FALSE(parser.parse_command("Report Robot", commandFactory));
    EXPECT_FALSE(parser.parse_command("move 1,1,North", commandFactory));
}
