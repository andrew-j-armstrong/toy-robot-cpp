#ifndef TOYROBOT_ICOMMAND_H_
#define TOYROBOT_ICOMMAND_H_

namespace ToyRobot
{
    class ICommand
    {
    public:
        virtual ~ICommand() {}

        virtual bool execute() const = 0;

    protected:
        ICommand() {}
    };
}

#endif
