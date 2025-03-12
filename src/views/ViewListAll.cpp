//
// Created by cicero on 20/02/25.
//

#include "Mock.h"
#include "Travel.h"

#include "ViewListAll.h"

#include <InterfaceManager.h>
#include <vector>
#include <ViewMenu.h>

void ViewListAll::output() {

    std::vector<Travel> travels = Mock::travelMocks;

    for (int i = 0; i < travels.size(); i++) std::cout << std::to_string(i + 1) + ". " + formatTravel(travels[i]) << std::endl;

    std::cout << std::endl << std::endl;
}

void ViewListAll::processInput(std::string &) {

    InterfaceManager::setCurrentView(new ViewMenu());
}

std::string ViewListAll::formatTravel(Travel travel) {

    return travel.getLocation() + ", " + formatStructure(travel.getStructure());
}

std::string ViewListAll::formatStructure(StageStructure structure) {

    return structure.getType() + " (" + formatSize(structure.getSize()) + ")";
}

std::string ViewListAll::formatSize(StageSize size) {

    return std::to_string(size.getWidth()) + " x " + std::to_string(size.getLength()) + " x " + std::to_string(size.getHeight());
}
