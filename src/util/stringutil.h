#ifndef TOYROBOT_STRINGUTIL_H_
#define TOYROBOT_STRINGUTIL_H_

#include <string>

namespace ToyRobot
{
    std::string to_lowercase(const std::string &input);

    std::string ltrim(const std::string &input);
    std::string rtrim(const std::string &input);
    std::string trim(const std::string &input);
}

#endif
