#include "textparser.h"

#include <string>
#include <regex>
#include <memory>

#include "../util/stringutil.h"
#include "../commands/icommand.h"
#include "../commands/icommandfactory.h"

using namespace ToyRobot;

// Note that if this changes then the match indexes might also need to be updated
#define COMMAND_REGEX "^((move)|(left)|(right)|(report)|(place +(-?\\d+) *, *(-?\\d+) *, *((north)|(east)|(south)|(west))))$"

TextParser::TextParser()
: m_regex(COMMAND_REGEX)
{
}

TextParser::~TextParser()
{
}

std::unique_ptr<ICommand> TextParser::parse_command(const std::string &text, const ICommandFactory &commandFactory) const
{
    // Simplifies and optimised regular expression
    std::string lowerText = to_lowercase(trim(text));
    std::smatch match;
    if (regex_search(lowerText, match, m_regex))
    {
        if (match[2].matched)
        {
            return move(commandFactory.new_move_command());
        }
        else if (match[3].matched)
        {
            return move(commandFactory.new_left_command());
        }
        else if (match[4].matched)
        {
            return move(commandFactory.new_right_command());
        }
        else if (match[5].matched)
        {
            return move(commandFactory.new_report_command());
        }
        else if (match[6].matched)
        {
            int x = std::stoi(match[7].str()); // Allowing exception on failed parse to fall through as the regular expression should mean it's impossible
            int y = std::stoi(match[8].str()); // Allowing exception on failed parse to fall through as the regular expression should mean it's impossible
            Direction facing = from_string(match[9].str());

            if (facing == UnknownDirection)
                return nullptr; // If the direction parsing failed, ignore the command. Note that this should be impossible due to the regular expression.

            return move(commandFactory.new_place_command(x, y, facing));
        }
    }

    return nullptr;
}
