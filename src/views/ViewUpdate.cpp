//
// Created by cicero on 12/03/25.
//

#include "ApplicationManager.h"
#include "Mock.h"
#include "TimeUtils.h"

#include "ViewUpdate.h"

#include <InterfaceManager.h>
#include <regex>
#include <ViewListAll.h>
#include <ViewMenu.h>

ViewUpdate::ViewUpdate() : currentSubView(ViewUpdate::MAIN), currentResult(0) {

    subViews.insert(subViews.end(), {&ViewUpdate::mainSubview, &ViewUpdate::showTravel, &ViewUpdate::showUpdatingOptions, &ViewUpdate::updateLocation, &ViewUpdate::updateStageType, &ViewUpdate::updateStageSize, &ViewUpdate::updateStartDate, &ViewUpdate::updateFinalDate});

    inputProcessors.insert(inputProcessors.end(), {&ViewUpdate::processInputFromMain, &ViewUpdate::processInputFromShowTravel, &ViewUpdate::processInputFromShowUpdatingOptions, &ViewUpdate::processInputFromUpdateLocation, &ViewUpdate::processInputFromUpdateStageType, &ViewUpdate::processInputFromUpdateStageSize, &ViewUpdate::processInputFromUpdateStartDate, &ViewUpdate::processInputFromUpdateFinalDate});

    travel = Travel();
}

void ViewUpdate::output() {

    (this ->*subViews[currentSubView])();
}

void ViewUpdate::processInput(std::string &input) {

    (this->*inputProcessors[currentSubView])(input);
}

void ViewUpdate::mainSubview() {

    std::cout << "Insira o nome (ou parte do nome) do local para pesquisar: " << std::endl;
}

void ViewUpdate::showTravel() {

    std::cout << ViewListAll::formatTravel(results[currentResult]) << std::endl << std::endl;

    std::cout << "1. Exibir anterior" << std::endl;
    std::cout << "2. Exibir próximo" << std::endl;
    std::cout << "3. Alterar" << std::endl;
    std::cout << "4. Voltar ao menu inicial" << std::endl;
}

void ViewUpdate::showUpdatingOptions() {

    StageSize stageSize = travel.getStructure().getSize();

    std::cout << "1. Destino: " + travel.getLocation() << std::endl;
    std::cout << "2. Tipo de palco: " + travel.getStructure().getType() << std::endl;
    std::cout << "3. Tamanho do palco: " + ViewListAll::formatStageSize(stageSize) << std::endl;
    std::cout << "4. Data de início: " << travel.getStartDate() << std::endl;
    std::cout << "5. Data de término: " << travel.getFinalDate() << std::endl;
    std::cout << "6. Salvar e retornar ao menu anterior" << std::endl;
    std::cout << "7. Salvar e cadastrar outra viagem" << std::endl;
    std::cout << "8. Retornar ao menu anterior sem salvar" << std::endl;
}

void ViewUpdate::processInputFromMain(std::string &input) {

    results.erase(results.begin(), results.end());

    // TODO: Modificar essa linha para usar a classe Repository
    results.insert(results.end(), Mock::travelMocks.begin(), Mock::travelMocks.end());

    std::cout << "Foram encontrados " << results.size() << " resultado(s). Exibindo o primeiro" << std::endl;

    if (!results.empty()) {

        currentResult = 0;

        currentSubView = ViewUpdate::SHOW_TRAVEL;
    }
    else InterfaceManager::setCurrentView(new ViewMenu());
}

void ViewUpdate::processInputFromShowTravel(std::string &input) {

    int option;

    try {
        option = std::stoi(input);
    }
    catch (std::invalid_argument &e) {
        option = -1;
    }

    switch(option) {

        case 1:
            if (currentResult > 0) --currentResult;
        break;

        case 2:
            if ( currentResult < (results.size() - 1) ) ++currentResult;
        break;

        case 3:
            travel = results[currentResult];

            currentSubView = SHOW_UPDATING_OPTIONS;
        break;

        case 4:
            InterfaceManager::setCurrentView(new ViewMenu());
        break;

        default:
            InterfaceManager::printInvalidOption();
    }
}

void ViewUpdate::processInputFromShowUpdatingOptions(std::string &input) {

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

void ViewUpdate::updateLocation() {

    std::cout << "Insira o novo destino: " << std::endl;
}

void ViewUpdate::updateStageType() {

    std::cout << "Insira o novo tipo de palco: " << std::endl;
}

void ViewUpdate::updateStageSize() {

    std::cout << "Insira o novo tamanho de palco (largura x comprimento x altura): " << std::endl;
}

void ViewUpdate::updateStartDate() {

    std::cout << "Insira a nova data de início (a-m-d): " << std::endl;
}

void ViewUpdate::updateFinalDate() {

    std::cout << "Insira a nova data de término (a-m-d): " << std::endl;
}

void ViewUpdate::processInputFromUpdateLocation(std::string &input) {

    travel.setLocation(input);

    currentSubView = ViewUpdate::SHOW_UPDATING_OPTIONS;
}

void ViewUpdate::processInputFromUpdateStageType(std::string &input) {

    StageStructure stage = travel.getStructure();

    stage.setType(input);

    travel.setStructure(stage);

    currentSubView = ViewUpdate::SHOW_UPDATING_OPTIONS;
}

void ViewUpdate::processInputFromUpdateStageSize(std::string &input) {

    std::string float_pattern = "\\d*[.]?(\\d)?";

    std::regex regex("(" + float_pattern + ") x (" + float_pattern + ") x (" + float_pattern + ")");

    std::smatch match;

    if (std::regex_match(input, match, regex)) {

        StageStructure stage = travel.getStructure();

        StageSize stageSize = StageSize(std::stof(match[1].str()), std::stof(match[3].str()), std::stof(match[5].str()));

        stage.setSize(stageSize);

        travel.setStructure(stage);

        currentSubView = ViewUpdate::SHOW_UPDATING_OPTIONS;
    }
    else {

        std::cout << "Formato inválido. Insira as dimensões do palco no formato largura x comprimento x altura" << std::endl;
    }
}

void ViewUpdate::processInputFromUpdateStartDate(std::string &input) {

    std::vector<int> result = TimeUtils::validateDate(input);

    if (result.size() == 3) {

        travel.setStartDate(result[0], result[1], result[2]);

        currentSubView = ViewUpdate::SHOW_UPDATING_OPTIONS;
    }
    else {

        std::cout << "Formato inválido. Insira a data no formato a-m-d" << std::endl;
    }
}

void ViewUpdate::processInputFromUpdateFinalDate(std::string &input) {

    std::vector<int> result = TimeUtils::validateDate(input);

    if (result.size() == 3) {

        travel.setFinalDate(result[0], result[1], result[2]);

        currentSubView = ViewUpdate::SHOW_UPDATING_OPTIONS;
    }
    else {

        std::cout << "Formato inválido. Insira a data no formato a-m-d" << std::endl;
    }
}
