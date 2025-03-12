//
// Created by cicero on 12/03/25.
//

#include "Mock.h"

#include "ShowTravel.h"

#include <InterfaceManager.h>
#include <iostream>
#include <ostream>
#include <ViewListAll.h>
#include <ViewMenu.h>

ShowTravel::ShowTravel() : currentSubView(ShowTravel::MAIN), currentResult(0) {

    subViews.insert(subViews.end(), {&ShowTravel::mainSubview, &ShowTravel::showTravel});

    inputProcessors.insert(inputProcessors.end(), {&ShowTravel::processInputFromMain, &ShowTravel::processInputFromShowTravel});

    travel = Travel();
}

void ShowTravel::output() {

    (this ->*subViews[currentSubView])();
}

void ShowTravel::processInput(std::string &input) {

    (this->*inputProcessors[currentSubView])(input);
}

void ShowTravel::mainSubview() {

    std::cout << "Insira o nome (ou parte do nome) do local para pesquisar: " << std::endl;
}

void ShowTravel::showTravel() {

    std::cout << ViewListAll::formatTravel(results[currentResult]) << std::endl << std::endl;

    std::cout << "1. Exibir anterior" << std::endl;
    std::cout << "2. Exibir próximo" << std::endl;
    std::cout << "3. Voltar ao menu inicial" << std::endl;
}


void ShowTravel::processInputFromMain(std::string &input) {
    results.erase(results.begin(), results.end());

    // TODO: Modificar essa linha para usar a classe Repository
    results.insert(results.end(), Mock::travelMocks.begin(), Mock::travelMocks.end());

    std::cout << "Foram encontrados " << results.size() << " resultado(s). Exibindo o primeiro" << std::endl;

    if (!results.empty()) {

        currentResult = 0;

        currentSubView = ShowTravel::SHOW_TRAVEL;
    }
    else InterfaceManager::setCurrentView(new ViewMenu());
}

void ShowTravel::processInputFromShowTravel(std::string &input) {

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
            InterfaceManager::setCurrentView(new ViewMenu());
        break;

        default:
            InterfaceManager::printInvalidOption();
    }
}
