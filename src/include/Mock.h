#ifndef MOCK_H
#define MOCK_H

#include <iostream>
#include <vector>
#include "Travel.h"

using namespace std;

//Classe criada para realização de testes

class Mock {

    private:
    vector<Travel> travel;;

    public:
    Mock ();
    void read();
    void print();
    
};

#endif //MOCK_H