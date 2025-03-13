//
// Created by cicero on 20/02/25.
//

#include "ApplicationManager.h"

#include "ViewInsert.h"
#include "date.h"
#include "TimeUtils.h"

#include <InterfaceManager.h>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <ViewMenu.h>


ViewInsert::ViewInsert() : currentSubView(ViewInsert::MAIN) {

    subViews.insert(subViews.end(), {&ViewInsert::mainMenu, &ViewInsert::updateLocation, &ViewInsert::updateStageType, &ViewInsert::updateStageSize, &ViewInsert::updateStartDate, &ViewInsert::updateFinalDate});

    inputProcessors.insert(inputProcessors.end(), {&ViewInsert::processInputFromMain, &ViewInsert::processInputFromUpdateLocation, &ViewInsert::processInputFromUpdateStageType, &ViewInsert::processInputFromUpdateStageSize, &ViewInsert::processInputFromUpdateStartDate, &ViewInsert::processInputFromUpdateFinalDate});

    travel = Travel();
}

void ViewInsert::output() {

    (this ->*subViews[currentSubView])();
}

void ViewInsert::mainMenu() {

    StageSize stageSize = travel.getStructure().getSize();

    std::cout << "1. Destino: " + travel.getLocation() << std::endl;
    std::cout << "2. Tipo de palco: " + travel.getStructure().getType() << std::endl;
    std::cout << "3. Tamanho do palco: " + formatStageSize(stageSize) << std::endl;
    std::cout << "4. Data de início: " << travel.getStartDate() << std::endl;
    std::cout << "5. Data de término: " << travel.getFinalDate() << std::endl;
    std::cout << "6. Salvar e retornar ao menu anterior" << std::endl;
    std::cout << "7. Salvar e cadastrar outra viagem" << std::endl;
    std::cout << "8. Retornar ao menu anterior sem salvar" << std::endl;
}

void ViewInsert::updateLocation() {

    std::cout << "Insira o novo destino: " << std::endl;
}

void ViewInsert::updateStageType() {

    std::cout << "Insira o novo tipo de palco: " << std::endl;
}

void ViewInsert::updateStageSize() {

    std::cout << "Insira o novo tamanho de palco (largura x comprimento x altura): " << std::endl;
}

void ViewInsert::updateStartDate() {

    std::cout << "Insira a nova data de início (a-m-d): " << std::endl;
}

void ViewInsert::updateFinalDate() {

    std::cout << "Insira a nova data de término (a-m-d): " << std::endl;
}

void ViewInsert::processInput(std::string &input) {

    (this->*inputProcessors[currentSubView])(input);
}

void ViewInsert::processInputFromMain(std::string &input) {

    int option;

    try {
        option = std::stoi(input);
    }
    catch (std::invalid_argument &e) {
        option = -1;
    }

    switch(option) {

        case 1:
            currentSubView = UPDATE_LOCATION;
        break;

        case 2:
            currentSubView = UPDATE_STAGE_TYPE;
        break;

        case 3:
            currentSubView = UPDATE_STAGE_SIZE;
        break;

        case 4:
            currentSubView = UPDATE_START_DATE;
        break;

        case 5:
            currentSubView = UPDATE_FINAL_DATE;
        break;

        case 6:
            ApplicationManager::repository.insert(travel);

            InterfaceManager::setCurrentView(new ViewMenu());
        break;

        case 7:
            ApplicationManager::repository.insert(travel);
        break;

        case 8:
            InterfaceManager::setCurrentView(new ViewMenu());
        break;

        default:
            InterfaceManager::printInvalidOption();
    }
}

void ViewInsert::processInputFromUpdateLocation(std::string &input) {

    travel.setLocation(input);

    currentSubView = MAIN;
}

void ViewInsert::processInputFromUpdateStageType(std::string &input) {

    StageStructure stage = travel.getStructure();

    stage.setType(input);

    travel.setStructure(stage);

    currentSubView = MAIN;
}

void ViewInsert::processInputFromUpdateStageSize(std::string &input) {

    std::string float_pattern = "\\d*[.]?(\\d)?";

    std::regex regex("(" + float_pattern + ") x (" + float_pattern + ") x (" + float_pattern + ")");

    std::smatch match;

    if (std::regex_match(input, match, regex)) {

        StageStructure stage = travel.getStructure();

        float i = std::stof(match[1].str());

        StageSize stageSize = StageSize(std::stof(match[1].str()), std::stof(match[3].str()), std::stof(match[5].str()));

        stage.setSize(stageSize);

        travel.setStructure(stage);

        currentSubView = MAIN;
    }
    else {

        std::cout << "Formato inválido. Insira as dimensões do palco no formato largura x comprimento x altura" << std::endl;
    }
}

void ViewInsert::processInputFromUpdateStartDate(std::string &input) {

    std::vector<int> result = TimeUtils::validateDate(input);

    if (result.size() == 3) {

        travel.setStartDate(result[0], result[1], result[2]);

        currentSubView = MAIN;
    }
    else {

        std::cout << "Formato inválido. Insira a data no formato a-m-d" << std::endl;
    }
}

void ViewInsert::processInputFromUpdateFinalDate(std::string &input) {

    std::vector<int> result = TimeUtils::validateDate(input);

    if (result.size() == 3) {

        travel.setFinalDate(result[0], result[1], result[2]);

        currentSubView = MAIN;
    }
    else {

        std::cout << "Formato inválido. Insira a data no formato a-m-d" << std::endl;
    }
}

std::string ViewInsert::formatStageSize(StageSize &size) {

    return std::to_string(size.getWidth()) + " x " + std::to_string(size.getLength()) + " x " + std::to_string(size.getHeight());
}