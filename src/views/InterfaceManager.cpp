//
// Created by cicero on 15/02/25.
//

#include "Travel.h"
#include "ViewMenu.h"

#include <InterfaceManager.h>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

ViewInterface *InterfaceManager::CURRENT_VIEW = new ViewMenu();

std::string InterfaceManager::getInput() {

    std::string input;

    std::getline(std::cin, input);

    return input;
}

void InterfaceManager::s_Insert() {

    Travel new_travel;

    std::string input;

    std::cin >> input;


}

void InterfaceManager::p_Insert(std::string &) {
}

void InterfaceManager::s_ListAll() {

    std::vector<Travel> new_travel;
}

void InterfaceManager::p_ListAll(std::string &) {
}

void InterfaceManager::update() {

    CURRENT_VIEW -> output();

    std::cout << std::endl;

    std::string input = getInput();

    std::cout << std::endl;

    CURRENT_VIEW -> processInput(input);
}

void InterfaceManager::setCurrentView(ViewInterface *view) {

    CURRENT_VIEW = view;
}

void InterfaceManager::printInvalidOption() {

    std::cout << "Opção inválida. Tente novamente." << std::endl << std::endl;
}
