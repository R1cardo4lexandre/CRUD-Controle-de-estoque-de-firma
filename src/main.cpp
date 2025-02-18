//
// Created by cicero on 06/01/25.
//

#include <iostream>
#include "Mock.h"
#include "ApplicationManager.h"

int main() {

    ApplicationManager::start();

    Mock mock = Mock();
    mock.read();
    mock.print();
}