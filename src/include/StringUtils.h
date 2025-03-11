//
// Created by cicero on 10/03/25.
//

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

//TODO: essa função não tá comentada

class StringUtils {

public:

    static std::string join(const std::vector<std::string>&, const std::string&);

    static std::vector<std::string> split(const std::string&, const std::string&);
};



#endif /* STRING_UTILS_H */
