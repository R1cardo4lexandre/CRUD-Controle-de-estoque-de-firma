//
// Created by cicero on 06/01/25.
//

#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H



class ApplicationManager {

public:

    static void start();

    static bool isDone();

private:

    static bool _done;
};



#endif //APPLICATIONMANAGER_H
