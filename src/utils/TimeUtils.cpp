//
// Created by cicero on 04/01/25.
//

#include "TimeUtils.h"
#include "date.h"

#include <chrono>
#include <iostream>
#include <regex>

using date::operator<<;

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

std::string TimeUtils::getTimeStamp(){

    const std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    std::ostringstream oss;

    return (oss << now, oss.str().substr(0, 23));
}

std::vector<int> TimeUtils::validateDate(std::string &input) {

    std::vector<int> result;

    std::regex regex(R"((\d{4,})-(\d{1,2})-(\d{1,2}))");

    std::smatch match;

    if (std::regex_match(input, match, regex)) {

        result.insert(result.end(), {std::stoi(match[1].str()), std::stoi(match[2].str()), std::stoi(match[3].str())});
    }

    return result;
}
