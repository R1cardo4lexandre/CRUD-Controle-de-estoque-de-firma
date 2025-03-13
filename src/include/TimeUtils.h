//
// Created by cicero on 04/01/25.
//

#ifndef TIMEUTILS_H
#define TIMEUTILS_H
#include <string>
#include <vector>


class TimeUtils {

public:

    static std::string getTimeStamp();

    static std::vector<int> validateDate(std::string &);
};



#endif //TIMEUTILS_H
