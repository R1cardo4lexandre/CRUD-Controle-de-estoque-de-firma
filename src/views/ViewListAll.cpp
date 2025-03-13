//
// Created by cicero on 20/02/25.
//

#include "Mock.h"
#include "Repository.h"
#include "Travel.h"

#include "ViewListAll.h"

#include <InterfaceManager.h>
#include <vector>
#include <ViewMenu.h>

void ViewListAll::output() {

    std::vector<Travel> travels = Repository::getAll();

    if (travels.empty()) std::cout << "Nenhuma viagem cadastrada" << std::endl;
    else {

        for (int i = 0; i < travels.size(); i++) std::cout << std::to_string(i + 1) + ". " + formatTravel(travels[i]) << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Digite qualquer coisa para voltar ao menu inicial" << std::endl;
}

void ViewListAll::processInput(std::string &) {

    InterfaceManager::setCurrentView(new ViewMenu());
}

std::string ViewListAll::formatTravel(Travel travel) {

    return travel.getLocation() + ", " + travel.getStartDate() + "-" + travel.getFinalDate() + ", " + formatStructure(travel.getStructure());
}

std::string ViewListAll::formatStructure(StageStructure structure) {

    return structure.getType() + " (" + formatStageSize(structure.getSize()) + ")";
}

std::string ViewListAll::formatStageSize(StageSize size) {

    return std::to_string(size.getWidth()) + " x " + std::to_string(size.getLength()) + " x " + std::to_string(size.getHeight());
}
