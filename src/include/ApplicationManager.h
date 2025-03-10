//
// Created by cicero on 06/01/25.
//

#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H
#include "DatabaseAPI.h"


class ApplicationManager {

public:

    static void start();

    static DatabaseAPI *database;
};



#endif //APPLICATIONMANAGER_H
