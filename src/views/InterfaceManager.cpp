//
// Created by cicero on 15/02/25.
//

#include "../include/InterfaceManager.h"

#include <chrono>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>
#include <vector>
#include <bits/atomic_base.h>

int InterfaceManager::CURRENT_VIEW = InterfaceManager::MENU;

std::vector<void (*)()> InterfaceManager::views = {InterfaceManager::s_Menu, InterfaceManager::s_Insert};

std::vector<void (*)(std::string&)> InterfaceManager::input_processors = {InterfaceManager::p_Menu, InterfaceManager::p_Insert};

void InterfaceManager::s_Menu() {

    const std::vector<std::string> OPTIONS = { "Inserir", "Listar todos", "Exibir um", "Alterar", "Remover", "Exibir Relatório", "Sair"};

    for (int i = 0; i < OPTIONS.size(); i++) std::cout << (i + 1) << ". " << OPTIONS[i] << std::endl;
}

std::string InterfaceManager::getInput() {

    std::string input;

    std::cin >> input;

    return input;
}

void InterfaceManager::p_Menu(std::string &input) {

    int option;

    try {
        option = std::stoi(input);
    }
    catch (std::invalid_argument &e) {
        option = -1;
    }

    switch (option) {

        case 1:
            CURRENT_VIEW = InterfaceManager::INSERT;
        break;

        default:
            printInvalidOption();
    }
}

void InterfaceManager::s_Insert() {
}

void InterfaceManager::update() {

    views[CURRENT_VIEW]();

    std::cout << std::endl;

    std::string input = getInput();

    std::cout << std::endl;

    input_processors[CURRENT_VIEW](input);
}

void InterfaceManager::printInvalidOption() {

    std::cout << "Opção inválida. Tente novamente." << std::endl << std::endl;
}
