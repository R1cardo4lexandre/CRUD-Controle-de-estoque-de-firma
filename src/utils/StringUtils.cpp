//
// Created by cicero on 10/03/25.
//

#include "StringUtils.h"

#include <regex>
#include <string>

std::string StringUtils::join(const std::vector<std::string> &toJoin, const std::string &delim) {

    std::string result = toJoin[0];

    for(unsigned int i = 1; i < toJoin.size(); ++i) result += delim + toJoin[i];

    return result;
}

std::vector<std::string> StringUtils::split(const std::string &s, const std::string &delimiter) {

    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));

    return res;
}

std::string StringUtils::formatFloat(float f, int precision) {

    std::string result = std::to_string(f);

    int pos = result.find('.');
}
