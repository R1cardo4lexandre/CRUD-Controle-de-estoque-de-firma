//
// Created by cicero on 20/02/25.
//

#ifndef VIEWLISTALL_H
#define VIEWLISTALL_H
#include "ViewInterface.h"


class ViewListAll : public ViewInterface{
protected:
    ~ViewListAll() = default;

public:
    void output() override;

    void processInput(std::string &) override;
};



#endif /* VIEWLISTALL_H */
