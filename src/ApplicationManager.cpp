//
// Created by cicero on 06/01/25.
//

#include "Database.h"
#include "ApplicationManager.h"
#include "Mock.h"

void ApplicationManager::start() {

    Mock::initMock();

    database = new Database();
}
