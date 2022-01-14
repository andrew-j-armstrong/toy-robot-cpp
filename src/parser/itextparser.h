#ifndef TOYROBOT_ITEXTPARSER_H_
#define TOYROBOT_ITEXTPARSER_H_

#include <memory>
#include <string>

#include "../commands/icommand.h"
#include "../commands/icommandfactory.h"

namespace ToyRobot
{
    class ITextParser
    {
    public:
        virtual ~ITextParser() {}

        virtual std::unique_ptr<ICommand> parse_command(const std::string &text) const = 0;

    protected:
        ITextParser() {}

    };
}

#endif
