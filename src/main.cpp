//
// Created by cicero on 06/01/25.
//

#include "InterfaceManager.h"
#include "ftxui/component/screen_interactive.hpp"
#include "include/ApplicationManager.h"

#include <ftxui/dom/table.hpp>
int main() {

    ApplicationManager::start();

    while (!ApplicationManager::isDone()) {

        InterfaceManager::update();

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}
