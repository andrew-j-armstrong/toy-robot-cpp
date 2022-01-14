#include <iostream>
#include <fstream>

#include "interface/istreaminput.h"
#include "interface/ostreamreporter.h"
#include "model/robot.h"
#include "model/table.h"
#include "parser/textparser.h"
#include "commands/commandfactory.h"

using namespace ToyRobot;

std::unique_ptr<IStreamInput> generate_input(const std::string &filename, std::ifstream &inputFile)
{
    if (filename.empty())
        return std::unique_ptr<IStreamInput>(new IStreamInput(std::cin));
    else
    {
        inputFile.open(filename);
        return std::unique_ptr<IStreamInput>(new IStreamInput(inputFile));
    }
}

bool parse_arguments(int argc, char *argv[], std::string &inputFilename)
{
    if (argc == 1)
    {
        inputFilename = "";
        return true;
    }
    else if (argc == 2)
    {
        inputFilename = argv[1];
        return true;
    }

    return false;
}

int main(int argc, char*argv[])
{
    std::string inputFilename;
    if (!parse_arguments(argc, argv, inputFilename))
    {
        std::cout << "Usage:" << std::endl
                  << "    ./toy_robot                   read from stdin" << std::endl
                  << "    ./toy_robot <filename>        read from file" << std::endl;
        exit(1);
    }

    std::ifstream inputFile;
    auto inputStream = generate_input(inputFilename, inputFile);

    std::shared_ptr<IReporter> reporter(new OStreamReporter(std::cout));
    std::shared_ptr<ISurface> table(new Table(5, 5));
    std::shared_ptr<IRobot> robot(new Robot());
    std::shared_ptr<ICommandFactory> commandFactory(new CommandFactory(robot, reporter, table));
    TextParser parser(commandFactory);

    std::string line;
    while(inputStream->read_line(line))
    {
        auto command = parser.parse_command(line);
        if (command)
            command->execute();
    }
}
