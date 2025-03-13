//
// Created by cicero on 12/03/25.
//

#ifndef VIEWUPDATE_H
#define VIEWUPDATE_H
#include "Travel.h"
#include "ViewInterface.h"

#include <vector>


class ViewUpdate : public ViewInterface{

public:

    ViewUpdate();
    void output() override;

    void processInput(std::string &) override;

    
private:
    Travel travel;

    enum SubViewsConstants {MAIN, SHOW_TRAVEL, SHOW_UPDATING_OPTIONS, UPDATE_LOCATION, UPDATE_STAGE_TYPE, UPDATE_STAGE_SIZE, UPDATE_START_DATE, UPDATE_FINAL_DATE};

    int currentSubView;

    std::vector<void (ViewUpdate::*)()> subViews;

    std::vector<void (ViewUpdate::*)(std::string&)> inputProcessors;

    std::vector<Travel> results;

    int currentResult;

    void mainSubview();

    void showTravel();

    void showUpdatingOptions();

    void processInputFromMain(std::string &input);

    void processInputFromShowTravel(std::string &input);

    void processInputFromShowUpdatingOptions(std::string &input);

    void updateLocation();

    void updateStageType();

    void updateStageSize();

    void updateStartDate();

    void updateFinalDate();

    void processInputFromUpdateLocation(std::string &);

    void processInputFromUpdateStageType(std::string &);

    void processInputFromUpdateStageSize(std::string &);

    void processInputFromUpdateStartDate(std::string &);

    void processInputFromUpdateFinalDate(std::string &);
};



#endif /* VIEWUPDATE_H */
