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
    std::shared_ptr<MockCommandFactory> commandFactory(new MockCommandFactory());
    TextParser parser(commandFactory);
    
    EXPECT_CALL(*commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_CALL(*commandFactory, new_move_command())
        .Times(4)
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("move"));
    EXPECT_TRUE(parser.parse_command(" Move"));
    EXPECT_TRUE(parser.parse_command("MOVE "));
    EXPECT_TRUE(parser.parse_command("\t MOve "));
}

// Test parsing left command
TEST(TextParserTest, ValidLeftCommand)
{
    std::shared_ptr<MockCommandFactory> commandFactory(new MockCommandFactory());
    TextParser parser(commandFactory);
    
    EXPECT_CALL(*commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_CALL(*commandFactory, new_left_command())
        .Times(4)
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("left"));
    EXPECT_TRUE(parser.parse_command(" Left"));
    EXPECT_TRUE(parser.parse_command("LEFT "));
    EXPECT_TRUE(parser.parse_command("\t LEft "));
}

// Test parsing right command
TEST(TextParserTest, ValidRightCommand)
{
    std::shared_ptr<MockCommandFactory> commandFactory(new MockCommandFactory());
    TextParser parser(commandFactory);
    
    EXPECT_CALL(*commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_CALL(*commandFactory, new_right_command())
        .Times(4)
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("right"));
    EXPECT_TRUE(parser.parse_command(" Right"));
    EXPECT_TRUE(parser.parse_command("RIGHT "));
    EXPECT_TRUE(parser.parse_command("\t RIght "));
}

// Test parsing report command
TEST(TextParserTest, ValidReportCommand)
{
    std::shared_ptr<MockCommandFactory> commandFactory(new MockCommandFactory());
    TextParser parser(commandFactory);
    
    EXPECT_CALL(*commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_CALL(*commandFactory, new_report_command())
        .Times(4)
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))))
        .WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("report"));
    EXPECT_TRUE(parser.parse_command(" Report"));
    EXPECT_TRUE(parser.parse_command("REPORT "));
    EXPECT_TRUE(parser.parse_command("\t REport "));
}

// Test parsing place command
TEST(TextParserTest, ValidPlaceCommand)
{
    std::shared_ptr<MockCommandFactory> commandFactory(new MockCommandFactory());
    TextParser parser(commandFactory);
    
    EXPECT_CALL(*commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_report_command()).Times(0);

    EXPECT_CALL(*commandFactory, new_place_command(1, 2, North)).Times(1).WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));
    EXPECT_CALL(*commandFactory, new_place_command(0, 0, South)).Times(1).WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));
    EXPECT_CALL(*commandFactory, new_place_command(-1, -2, West)).Times(1).WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));
    EXPECT_CALL(*commandFactory, new_place_command(15, 15, East)).Times(1).WillOnce(Return(ByMove(move(std::unique_ptr<ICommand>(new MockCommand())))));

    EXPECT_TRUE(parser.parse_command("place 1,2,north"));
    EXPECT_TRUE(parser.parse_command(" Place 0, 0, South"));
    EXPECT_TRUE(parser.parse_command("PLACE -1 , -2 , WEST"));
    EXPECT_TRUE(parser.parse_command("\t pLAce 15,15, eASt \n"));
}

// Test parsing place commands with invalid parameters
TEST(TextParserTest, InvalidPlaceCommand)
{
    std::shared_ptr<MockCommandFactory> commandFactory(new MockCommandFactory());
    TextParser parser(commandFactory);
    
    EXPECT_CALL(*commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_FALSE(parser.parse_command("place 1 2 north"));
    EXPECT_FALSE(parser.parse_command("place 1,2"));
    EXPECT_FALSE(parser.parse_command("place 1,2,nort"));
    EXPECT_FALSE(parser.parse_command("place ,,"));
    EXPECT_FALSE(parser.parse_command("place 0,,north"));
    EXPECT_FALSE(parser.parse_command("place ,0,north"));
    EXPECT_FALSE(parser.parse_command("place 1,2,,north"));
}

// Test invalid commands similar to valid commands
TEST(TextParserTest, InvalidCommand)
{
    std::shared_ptr<MockCommandFactory> commandFactory(new MockCommandFactory());
    TextParser parser(commandFactory);
    
    EXPECT_CALL(*commandFactory, new_move_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_left_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_right_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_report_command()).Times(0);
    EXPECT_CALL(*commandFactory, new_place_command(_, _, _)).Times(0);

    EXPECT_FALSE(parser.parse_command("blah"));
    EXPECT_FALSE(parser.parse_command("movey"));
    EXPECT_FALSE(parser.parse_command("1left"));
    EXPECT_FALSE(parser.parse_command("right right"));
    EXPECT_FALSE(parser.parse_command("Report Robot"));
    EXPECT_FALSE(parser.parse_command("move 1,1,North"));
}
