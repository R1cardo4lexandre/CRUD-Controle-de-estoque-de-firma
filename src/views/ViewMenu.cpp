//
// Created by cicero on 19/02/25.
//

#include "InterfaceManager.h"
#include "ViewListAll.h"

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

        case 2:
            InterfaceManager::setCurrentView(new ViewListAll());
        break;

        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            std::cout << "Essa opção ainda não foi implementada" << std::endl;
        break;

        default:
            InterfaceManager::printInvalidOption();
    }
}
