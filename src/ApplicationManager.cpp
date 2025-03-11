//
// Created by cicero on 06/01/25.
//

#include "Database.h"
#include "ApplicationManager.h"
#include "Repository.h"

DatabaseAPI* ApplicationManager::database = nullptr;

void ApplicationManager::start() {

    database = new Database();
}
