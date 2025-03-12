//
// Created by cicero on 06/01/25.
//

#include "InterfaceManager.h"
#include "ApplicationManager.h"

#include <thread>

int main() {

    ApplicationManager::start();

    while (!ApplicationManager::isDone()) {

        InterfaceManager::update();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}