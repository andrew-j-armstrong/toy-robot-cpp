#include <iostream>
#include <fstream>

#include "interface/istreaminput.h"
#include "interface/ostreamreporter.h"
#include "model/robot.h"
#include "model/table.h"
#include "parser/textparser.h"
#include "commands/commandfactory.h"
#include "simulation.h"

using namespace ToyRobot;

std::unique_ptr<IInput> generate_input(const std::string &filename, std::ifstream &inputFile)
{
    if (filename.empty())
        return std::unique_ptr<IInput>(new IStreamInput(std::cin));
    else
    {
        inputFile.open(filename);
        return std::unique_ptr<IInput>(new IStreamInput(inputFile));
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
    auto input = generate_input(inputFilename, inputFile);

    std::unique_ptr<IReporter> reporter(new OStreamReporter(std::cout));
    std::unique_ptr<ISurface> table(new Table(5, 5));
    std::unique_ptr<IRobot> robot(new Robot());
    std::unique_ptr<ICommandFactory> commandFactory(new CommandFactory(move(robot), move(reporter), move(table)));
    std::unique_ptr<ITextParser> parser(new TextParser(move(commandFactory)));

    run_simulation(move(input), move(parser));
}
