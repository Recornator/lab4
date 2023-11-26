#pragma once
#include <string>
#include <sstream>
#include <vector>

class StringHelper
{
public:
    static std::string join(const std::vector<std::string>& vec, const char* delim);
    static std::vector<std::string> split(std::string strToSplit, char delimeter);
    static std::string replaceFirstOccurrence(
        std::string& s,
        const std::string& toReplace,
        const std::string& replaceWith);
    static std::vector<std::string> tokenize(std::string s, std::string del = " ");
    static const char qr[3];
    static const char ql[3];
};
