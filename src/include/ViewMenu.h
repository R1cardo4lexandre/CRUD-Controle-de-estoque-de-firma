//
// Created by cicero on 19/02/25.
//

#ifndef VIEWMENU_H
#define VIEWMENU_H
#include "ViewInterface.h"

class InterfaceManager;

class ViewMenu : public ViewInterface {
protected:
    ~ViewMenu() = default;

public:
    void output() override;

    void processInput(std::string &) override;
};



#endif /* VIEWMENU_H */
