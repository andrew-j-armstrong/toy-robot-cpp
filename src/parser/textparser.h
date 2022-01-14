#ifndef TOYROBOT_TEXTPARSER_H_
#define TOYROBOT_TEXTPARSER_H_

#include <regex>
#include <memory>

#include "itextparser.h"
#include "../commands/icommandfactory.h"

namespace ToyRobot
{
    class TextParser : public ITextParser
    {
    public:
        TextParser(std::shared_ptr<const ICommandFactory> commandFactory);
        virtual ~TextParser();

        std::unique_ptr<ICommand> parse_command(const std::string &text) const override;

    private:
        std::shared_ptr<const ICommandFactory> m_commandFactory;
        std::regex m_regex;
    };
}

#endif
