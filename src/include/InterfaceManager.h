//
// Created by cicero on 15/02/25.
//

#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H
#include <string>
#include <vector>


class InterfaceManager {

public:

    static void update();

private:

    static int CURRENT_VIEW;

    enum VIEW_CONSTANTS {MENU, INSERT};

    static std::vector<void (*)()> views;

    static std::vector<void (*)(std::string&)> input_processors;

    static std::string getInput();

    static void s_Menu();

    static void p_Menu(std::string&);

    static void s_Insert();

    static void p_Insert(std::string&);

    static void printInvalidOption();
};
#endif /* INTERFACEMANAGER_H */
