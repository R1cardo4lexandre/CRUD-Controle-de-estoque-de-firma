//
// Created by cicero on 10/03/25.
//

#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string>
#include <vector>


class StringUtils {

public:

    static std::string join(const std::vector<std::string>&, const std::string&);

    static std::vector<std::string> split(const std::string&, const std::string&);

    static std::string formatFloat(float, int);
};



#endif /* STRINGUTILS_H */
