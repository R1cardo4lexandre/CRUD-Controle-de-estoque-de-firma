//
// Created by cicero on 06/01/25.
//

#include "Database.h"
#include "ApplicationManager.h"
#include "Repository.h"
#include "InterfaceManager.h"
#include "Mock.h"

DatabaseAPI* ApplicationManager::database = nullptr;

bool ApplicationManager::_done = false;

void ApplicationManager::start() {

    database = new Database();

    repository = Repository();
}

void ApplicationManager::finish() {

    database -> clear();

    Repository::save();
}

bool ApplicationManager::isDone() {

    return _done;
}

void ApplicationManager::setDone(bool state) {

    _done = state;
}
