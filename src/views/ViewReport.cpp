//
// Created by cicero on 13/03/25.
//

#include "Repository.h"
#include "ViewReport.h"
#include "InterfaceManager.h"
#include "ViewMenu.h"

#include <iostream>

void ViewReport::output() {

    std::cout << Repository::getAll().size() << " viagens cadastradas" << std::endl << std::endl;

    std::cout << "Digite qualquer coisa para voltar ao menu inicial" << std::endl;
}

void ViewReport::processInput(std::string &input) {

    InterfaceManager::setCurrentView(new ViewMenu());
}
