#ifndef TOYROBOT_TEXTPARSER_H_
#define TOYROBOT_TEXTPARSER_H_

#include <regex>

#include "itextparser.h"

namespace ToyRobot
{
    class TextParser : public ITextParser
    {
    public:
        TextParser();
        virtual ~TextParser();

        std::unique_ptr<ICommand> parse_command(const std::string &text, const ICommandFactory &commandFactory) const override;

    protected:
        std::regex m_regex;
    };
}

#endif
