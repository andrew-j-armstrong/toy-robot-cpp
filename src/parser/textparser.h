#ifndef TOYROBOT_TEXTPARSER_H_
#define TOYROBOT_TEXTPARSER_H_

#include <regex>
#include <memory>

#include "itextparser.h"
#include "../commands/icommandfactory.h"

namespace ToyRobot
{
    // TextParser uses a command factory to generate command objects once it has decoded the commands and their arguments
    class TextParser : public ITextParser
    {
    public:
        // The constructor of TextParser can throw an exception if the command factory is invalid
        TextParser(std::shared_ptr<const ICommandFactory> commandFactory);
        virtual ~TextParser();

        std::unique_ptr<ICommand> parse_command(const std::string &text) const override;

    private:
        std::shared_ptr<const ICommandFactory> m_commandFactory;
        std::regex m_regex;
    };
}

#endif
