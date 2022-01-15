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

        execl(command, command, NULL);

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

// Tests that to_lowercase converts uppercase characters to lowercase while ignoring other characters
TEST(ToyRobotTest, StdInTest)
{
    EXPECT_EQ("1,2,NORTH\n", execProcess("bin/toy_robot", "PLACE 1,1,NORTH\nMOVE\nREPORT\nEXIT\n"));
}
