//
// Created by cicero on 06/01/25.
//

#include "Database.h"
#include "ApplicationManager.h"
#include "Repository.h"
#include "InterfaceManager.h"

DatabaseAPI* ApplicationManager::database = nullptr;

bool ApplicationManager::_done = false;

void ApplicationManager::start() {
}

    database = new Database();
bool ApplicationManager::isDone() {

    return _done;
}
