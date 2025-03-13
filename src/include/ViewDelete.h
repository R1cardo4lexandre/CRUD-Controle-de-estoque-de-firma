//
// Created by cicero on 13/03/25.
//

#ifndef VIEWDELETE_H
#define VIEWDELETE_H

#include "Travel.h"
#include "ViewInterface.h"
#include "ViewShowTravel.h"

#include <vector>


class ViewDelete : public ViewInterface{
public:
    ViewDelete();

    void output() override;

    void processInput(std::string &) override;

private:

    Travel travel;

    static std::string formatStageSize(StageSize&);

    enum SubViewsConstants {MAIN, SHOW_TRAVEL, UPDATE_STAGE_TYPE, UPDATE_STAGE_SIZE, UPDATE_START_DATE, UPDATE_FINAL_DATE};

    int currentSubView;

    std::vector<void (ViewDelete::*)()> subViews;

    std::vector<void (ViewDelete::*)(std::string&)> inputProcessors;

    std::vector<Travel> results;

    int currentResult;

    void mainSubview();

    void showTravel();

    void processInputFromMain(std::string &input);

    void processInputFromShowTravel(std::string &input);
};



#endif /* VIEWDELETE_H */
