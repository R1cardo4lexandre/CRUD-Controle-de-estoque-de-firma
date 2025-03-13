//
// Created by cicero on 13/03/25.
//

#include "InterfaceManager.h"
#include "Mock.h"
#include "Repository.h"
#include "ViewListAll.h"
#include "ViewMenu.h"
#include "ViewDelete.h"

ViewDelete::ViewDelete() : currentSubView(ViewDelete::MAIN), currentResult(0) {

    this -> subViews.insert(subViews.end(), {&ViewDelete::mainSubview, &ViewDelete::showTravel});

    inputProcessors.insert(inputProcessors.end(), {&ViewDelete::processInputFromMain, &ViewDelete::processInputFromShowTravel});

    travel = Travel();
}

void ViewDelete::output() {

    (this ->*subViews[currentSubView])();
}

void ViewDelete::processInput(std::string &input) {

    (this->*inputProcessors[currentSubView])(input);
}

void ViewDelete::mainSubview() {

    std::cout << "Insira o nome (ou parte do nome) do local para pesquisar: " << std::endl;
}

void ViewDelete::showTravel() {

    std::cout << ViewListAll::formatTravel(results[currentResult]) << std::endl << std::endl;

    std::cout << "1. Exibir anterior" << std::endl;
    std::cout << "2. Exibir próximo" << std::endl;
    std::cout << "3. Excluir" << std::endl;
    std::cout << "4. Voltar ao menu inicial" << std::endl;
}


void ViewDelete::processInputFromMain(std::string &input) {
    results.erase(results.begin(), results.end());

    for (Travel t : Repository::search(input)) {results.emplace_back(t);}

    std::cout << "Foram encontrados " << results.size() << " resultado(s). Exibindo o primeiro" << std::endl << std::endl;

    if (!results.empty()) {

        currentResult = 0;

        currentSubView = ViewDelete::SHOW_TRAVEL;
    }
    else InterfaceManager::setCurrentView(new ViewMenu());
}

void ViewDelete::processInputFromShowTravel(std::string &input) {

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
            Repository::deleteTravel(results[currentResult]);

            InterfaceManager::setCurrentView(new ViewMenu());
        break;

        case 4:
            InterfaceManager::setCurrentView(new ViewMenu());
        break;

        default:
            InterfaceManager::printInvalidOption();
    }
}

