//
// Created by cicero on 20/02/25.
//

#ifndef VIEWLISTALL_H
#define VIEWLISTALL_H

#include "ViewDelete.h"
#include "ViewShowTravel.h"
#include "ViewInterface.h"
#include "ViewUpdate.h"


class ViewListAll : public ViewInterface{

public:
    void output() override;

    void processInput(std::string &) override;

    friend ViewShowTravel;

    friend ViewUpdate;

    friend ViewDelete;

protected:
    ~ViewListAll() = default;

private:

    static std::string formatTravel(Travel);

    static std::string formatStructure(StageStructure);

    static std::string formatStageSize(StageSize);
};



#endif /* VIEWLISTALL_H */
