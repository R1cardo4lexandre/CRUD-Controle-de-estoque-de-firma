//
// Created by cicero on 06/01/25.
//

#include "ApplicationManager.h"
#include "Database.h"
#include "Mock.h"

void ApplicationManager::start() {

    Mock::initMock();

    database = new Database();
}
