//
// Created by cicero on 15/02/25.
//

#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H

#include "ViewInterface.h"

#include <string>
#include <vector>


class InterfaceManager {

public:

    static void update();

    static void printInvalidOption();

    static void setCurrentView(ViewInterface *);

private:

    static ViewInterface *CURRENT_VIEW;

    enum VIEW_CONSTANTS {MENU, INSERT, LIST_ALL};

    static std::vector<void (*)()> views;

    static std::vector<void (*)(std::string&)> input_processors;

    static std::string getInput();

    static void s_Menu();

    static void p_Menu(std::string&);

    static void s_Insert();

    static void p_Insert(std::string&);

    static void s_ListAll();

    static void p_ListAll(std::string&);
};
#endif /* INTERFACEMANAGER_H */
