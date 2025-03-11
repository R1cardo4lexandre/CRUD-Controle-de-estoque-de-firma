//
// Created by cicero on 04/01/25.
//

#include "date.h"
#include "TimeUtils.h"

#include <chrono>
#include <iostream>

using date::operator<<;

/*********************************************************************************************************
**********************************************************************************************************
*********************************************************************************************************/

std::string TimeUtils::getTimeStamp(){

    const std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    std::ostringstream oss;

    return (oss << now, oss.str().substr(0, 23));
}
