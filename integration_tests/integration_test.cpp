#include <gtest/gtest.h>

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#include<unistd.h>
#include<sys/wait.h>
#include<sys/prctl.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define READ 0
#define WRITE 1

// popen2 adapted from https://dzone.com/articles/simple-popen2-implementation
pid_t popen2(const char *command, int *inputFd, int *outputFd)
{
    int inputPipe[2], outputPipe[2];
    if (pipe(inputPipe) != 0 || pipe(outputPipe) != 0)
        return -1;

    pid_t pid = fork();
    if (pid < 0)
        return pid; // Fork failed
    else if (pid == 0)
    {
        // Child process
        close(inputPipe[WRITE]);
        dup2(inputPipe[READ], READ);
        close(outputPipe[READ]);
        dup2(outputPipe[WRITE], WRITE);

        execl("/bin/sh", "sh", "-c", command, NULL);

        // execl failed
        perror("execl");
        exit(1);
    }

    // Parent process
    close(inputPipe[READ]);
    if (inputFd == NULL)
        close(inputPipe[WRITE]);
    else
        *inputFd = inputPipe[WRITE];

    close(outputPipe[WRITE]);
    if (outputFd == NULL)
        close(outputPipe[READ]);
    else
        *outputFd = outputPipe[READ];

    return pid;
}

std::string execProcess(const std::string &cmd, const std::string &input)
{
    int inputFd, outputFd;
    char buf[128];

    pid_t pid = popen2(cmd.c_str(), &inputFd, &outputFd);

    if (pid <= 0)
    {
        std::cerr << "Unable to exec " << cmd << std::endl;
        exit(1);
        return "";
    }

    // Note this has potential to cause a deadlock if the input or output buffers fill up
    write(inputFd, input.c_str(), input.length());
    close(inputFd);

    std::string output;
    ssize_t charsRead = 0;
    while(0 < (charsRead = read(outputFd, buf, 127)))
    {
        buf[charsRead] = '\0';
        output += buf;
    }

    close(outputFd);
    return output;
}

// Tests that the toy robot app executes and exits with an exit command
TEST(ToyRobotTest, ImmediateExit)
{
    EXPECT_EQ("", execProcess("bin/toy_robot", "EXIT\n"));
}

// Tests that the robot correctly responds to all movement commands after being placed
TEST(ToyRobotTest, AllMovement)
{
    EXPECT_EQ("1,1,NORTH\n", execProcess("bin/toy_robot", "PLACE 1,1,NORTH\nREPORT\nEXIT\n"));
    EXPECT_EQ("1,2,NORTH\n", execProcess("bin/toy_robot", "PLACE 1,1,NORTH\nMOVE\nREPORT\nEXIT\n"));
    EXPECT_EQ("1,1,WEST\n", execProcess("bin/toy_robot", "PLACE 1,1,NORTH\nLEFT\nREPORT\nEXIT\n"));
    EXPECT_EQ("1,1,EAST\n", execProcess("bin/toy_robot", "PLACE 1,1,NORTH\nRIGHT\nREPORT\nEXIT\n"));
}

// Tests the examples provided in the problem specifications
TEST(ToyRobotTest, DualPlacement)
{
    EXPECT_EQ("1,1,NORTH\n3,3,EAST\n", execProcess("bin/toy_robot", "PLACE 1,1,NORTH\nREPORT\nPLACE 3,3,EAST\nREPORT\nEXIT\n"));
}

// Tests that commands issued prior to placement are ignored
TEST(ToyRobotTest, IgnorePriorToPlacement)
{
    EXPECT_EQ("2,2,SOUTH\n", execProcess("bin/toy_robot", "MOVE\nLEFT\nRIGHT\nREPORT\nPLACE 2,2,SOUTH\nREPORT\nEXIT\n"));
}

// Tests that invalid commands are ignored
TEST(ToyRobotTest, IgnoreInvalidCommands)
{
    EXPECT_EQ("2,2,SOUTH\n", execProcess("bin/toy_robot", "PLACE 2,2,SOUTH\nBLAH\nMOVE UP\nMOVE NORTH\nTURN LEFT\nRIGHT TURN\nJUMP\nPLACE SOUTH\nPLACE 4,4\nREPORT\nEXIT\n"));
}

// Tests the examples provided in the problem specifications
TEST(ToyRobotTest, ProblemExamples)
{
    EXPECT_EQ("0,1,NORTH\n", execProcess("bin/toy_robot", "PLACE 0,0,NORTH\nMOVE\nREPORT\nEXIT\n"));
    EXPECT_EQ("0,0,WEST\n", execProcess("bin/toy_robot", "PLACE 0,0,NORTH\nLEFT\nREPORT\nEXIT\n"));
    EXPECT_EQ("3,3,NORTH\n", execProcess("bin/toy_robot", "PLACE 1,2,EAST\nMOVE\nMOVE\nLEFT\nMOVE\nREPORT\nEXIT\n"));
}

// Tests the examples provided in the problem specifications
TEST(ToyRobotTest, FileInput)
{
    EXPECT_EQ("0,1,NORTH\n0,0,WEST\n3,3,NORTH\n", execProcess("bin/toy_robot integration_tests/examples.txt", ""));
}
