//
// Created by cicero on 13/03/25.
//

#ifndef VIEWREPORT_H
#define VIEWREPORT_H
#include "ViewInterface.h"


class ViewReport : public ViewInterface{
public:
    void output() override;

    void processInput(std::string &) override;
};



#endif /* VIEWREPORT_H */
