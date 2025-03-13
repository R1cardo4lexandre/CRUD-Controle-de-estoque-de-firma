//
// Created by cicero on 06/01/25.
//

#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H
#include "DatabaseAPI.h"

#include <Repository.h>


class ApplicationManager {

public:

    static void start();

    static void finish();

    static bool isDone();

    static DatabaseAPI *database;

    static Repository repository;

    static void setDone(bool);

private:

    static bool _done;
};



#endif //APPLICATIONMANAGER_H
