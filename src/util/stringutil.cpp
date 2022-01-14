#include "stringutil.h"

#include <algorithm>
#include <cctype>

// From https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
std::string ToyRobot::to_lowercase(const std::string &input)
{
    std::string output(input);
    std::transform(output.begin(), output.end(), output.begin(),
        [](unsigned char c){ return std::tolower(c); });

    return output;
}

// From https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
const std::string WHITESPACE = " \n\r\t\f\v";

std::string ToyRobot::ltrim(const std::string &input)
{
    size_t start = input.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : input.substr(start);
}
 
std::string ToyRobot::rtrim(const std::string &input)
{
    size_t end = input.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : input.substr(0, end + 1);
}
 
std::string ToyRobot::trim(const std::string &input) {
    return rtrim(ltrim(input));
}
