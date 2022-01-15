#include "textparser.h"

#include <string>
#include <regex>
#include <memory>

#include "../util/stringutil.h"
#include "../commands/icommand.h"
#include "../commands/icommandfactory.h"

using namespace ToyRobot;

// Note that if this changes then the match group indexes might also need to be updated
#define COMMAND_REGEX "^((move)|(left)|(right)|(report)|(exit)|(place +(-?\\d+) *, *(-?\\d+) *, *((north)|(east)|(south)|(west))))$"

TextParser::TextParser(std::shared_ptr<const ICommandFactory> commandFactory)
: m_commandFactory(move(commandFactory))
, m_regex(COMMAND_REGEX)
{
    if (!m_commandFactory)
        throw std::invalid_argument("command factory");
}

TextParser::~TextParser()
{
}

std::unique_ptr<ICommand> TextParser::parse_command(const std::string &text) const
{
    std::string lowerText = to_lowercase(trim(text)); // trimming & converting to lowercase simplifies and optimises the regular expression

    std::smatch match;
    if (regex_search(lowerText, match, m_regex))
    {
        if (match[2].matched) // (move)
        {
            return move(m_commandFactory->new_move_command());
        }
        else if (match[3].matched) // (left)
        {
            return move(m_commandFactory->new_left_command());
        }
        else if (match[4].matched) // (right)
        {
            return move(m_commandFactory->new_right_command());
        }
        else if (match[5].matched) // (report)
        {
            return move(m_commandFactory->new_report_command());
        }
        else if (match[6].matched) // (exit)
        {
            return move(m_commandFactory->new_exit_command());
        }
        else if (match[7].matched) // (place +(-?\\d+) *, *(-?\\d+) *, *((north)|(east)|(south)|(west)))
        {
            // Note: allowing exceptions on failed stoi parses to fall through as the regular expression should mean it's impossible
            int x = std::stoi(match[8].str()); // (-?\\d+)
            int y = std::stoi(match[9].str()); // (-?\\d+)
            Direction facing = from_string(match[10].str()); // ((north)|(east)|(south)|(west))

            if (facing == UnknownDirection)
                return nullptr; // If the direction parsing failed, ignore the command. Note that this should be impossible due to the regular expression.

            // Note that the place command is not validated during parsing; in theory the validity of a location on a surface
            // may change during the simulation, so the parser won't assume any particular location will always be invalid
            return move(m_commandFactory->new_place_command(x, y, facing));
        }
    }

    return nullptr;
}
