//
// Created by cicero on 06/01/25.
//

#include "ApplicationManager.h"
#include "Mock.h"

#include "Log.h"

void ApplicationManager::start() {

    //Log::initLog();

    Mock::initMock();
}
