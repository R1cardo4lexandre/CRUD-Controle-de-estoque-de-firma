//
// Created by cicero on 12/03/25.
//

#ifndef SHOWTRAVEL_H
#define SHOWTRAVEL_H
#include "Travel.h"
#include "ViewInterface.h"

#include <vector>


class ShowTravel : public ViewInterface{
public:
    ShowTravel();

    void output() override;

    void processInput(std::string &) override;

private:

    Travel travel;

    static std::string formatStageSize(StageSize&);

    enum SubViewsConstants {MAIN, SHOW_TRAVEL, UPDATE_STAGE_TYPE, UPDATE_STAGE_SIZE, UPDATE_START_DATE, UPDATE_FINAL_DATE};

    int currentSubView;

    std::vector<void (ShowTravel::*)()> subViews;

    std::vector<void (ShowTravel::*)(std::string&)> inputProcessors;

    std::vector<Travel> results;

    int currentResult;

    void mainSubview();

    void showTravel();

    void processInputFromMain(std::string &input);

    void processInputFromShowTravel(std::string &input);
};



#endif /* SHOWTRAVEL_H */
