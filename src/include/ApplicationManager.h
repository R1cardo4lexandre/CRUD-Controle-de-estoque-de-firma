//
// Created by cicero on 06/01/25.
//

#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DatabaseAPI.h"

//TODO: essa função não tá comentada

class ApplicationManager {

public:

    static void start();

    static DatabaseAPI *database;
};



#endif //APPLICATION_MANAGER_H
