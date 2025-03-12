//
// Created by cicero on 20/02/25.
//

#ifndef VIEWLISTALL_H
#define VIEWLISTALL_H

#include "ShowTravel.h"
#include "ViewInterface.h"


class ViewListAll : public ViewInterface{

public:
    void output() override;

    void processInput(std::string &) override;

    friend ShowTravel;

protected:
    ~ViewListAll() = default;

private:

    static std::string formatTravel(Travel);

    static std::string formatStructure(StageStructure);

    static std::string formatSize(StageSize);
};



#endif /* VIEWLISTALL_H */
