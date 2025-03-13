//
// Created by cicero on 19/02/25.
//

#include "ApplicationManager.h"
#include "InterfaceManager.h"
#include "ViewShowTravel.h"
#include "ViewInsert.h"
#include "ViewListAll.h"
#include "ViewReport.h"
#include "ViewUpdate.h"

#include "ViewMenu.h"

#include <iostream>
#include <ostream>
#include <vector>

void ViewMenu::output() {

    const std::vector<std::string> OPTIONS = { "Inserir", "Listar todos", "Exibir um", "Alterar", "Remover", "Exibir Relatório", "Sair"};

    for (int i = 0; i < OPTIONS.size(); i++) std::cout << (i + 1) << ". " << OPTIONS[i] << std::endl;
}

void ViewMenu::processInput(std::string &input) {
    int option;

    try {
        option = std::stoi(input);
    }
    catch (std::invalid_argument &e) {
        option = -1;
    }

    switch(option){

        case 1:
            InterfaceManager::setCurrentView(new ViewInsert());
        break;

        case 2:
            InterfaceManager::setCurrentView(new ViewListAll());
        break;

        case 3:
            InterfaceManager::setCurrentView(new ViewShowTravel());
        break;

        case 4:
            InterfaceManager::setCurrentView(new ViewUpdate());
        break;

        case 5:
            InterfaceManager::setCurrentView(new ViewDelete());
        break;

        case 6:
            InterfaceManager::setCurrentView(new ViewReport());
        break;

        case 7:
            ApplicationManager::setDone(true);
        break;

        default:
            InterfaceManager::printInvalidOption();
    }
}
