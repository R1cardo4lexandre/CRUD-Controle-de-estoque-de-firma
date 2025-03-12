//
// Created by cicero on 20/02/25.
//

#ifndef VIEWINSERT_H
#define VIEWINSERT_H

#include "Travel.h"
#include "ViewInterface.h"

#include <vector>


class ViewInsert : public ViewInterface {
public:

    ViewInsert();

    void output() override;

    void processInput(std::string &) override;

private:

    Travel travel;

    static std::string formatStageSize(StageSize&);

    enum SubViewsConstants {MAIN, UPDATE_LOCATION, UPDATE_STAGE_TYPE, UPDATE_STAGE_SIZE, UPDATE_START_DATE, UPDATE_FINAL_DATE};

    int currentSubView;

    std::vector<void (ViewInsert::*)()> subViews;

    std::vector<void (ViewInsert::*)(std::string&)> inputProcessors;

    void mainMenu();

    void updateLocation();

    void updateStageType();

    void updateStageSize();

    void updateStartDate();

    void updateFinalDate();

    void processInputFromMain(std::string &);

    void processInputFromUpdateLocation(std::string &);

    void processInputFromUpdateStageType(std::string &);

    void processInputFromUpdateStageSize(std::string &);

    void processInputFromUpdateStartDate(std::string &);

    void processInputFromUpdateFinalDate(std::string &);
};




#endif /* VIEWINSERT_H */
