//
// Created by cicero on 19/02/25.
//

#ifndef VIEWINTERFACE_H
#define VIEWINTERFACE_H

#include <string>


class ViewInterface {
public:
    ~ViewInterface();
    virtual void output() = 0;
    virtual void processInput(std::string&) = 0;

protected:
};

inline ViewInterface::~ViewInterface() {
}


#endif /* VIEWINTERFACE_H */
