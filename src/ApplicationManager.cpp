//
// Created by cicero on 06/01/25.
//

#include "InterfaceManager.h"

#include "include/ApplicationManager.h"

#include "include/Log.h"

bool ApplicationManager::_done = false;

void ApplicationManager::start() {
}

bool ApplicationManager::isDone() {

    return _done;
}
