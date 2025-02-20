#ifndef MOCK_H
#define MOCK_H

#include <iostream>
#include <vector>
#include "Travel.h"

using namespace std;

//Classe criada para realização de testes

class Mock {

    private:
    static vector<Travel> travelmocks;
    static vector<float> floatmocks;
    static vector<std::string> stringmocks1;
    static vector<std::string> stringmocks2;
    static vector<int> datemocks;

    public:
    Mock ();
    void read(); // TODO: esse método deveria ser estático; também seria bom mudar o nome dele para algo como "initMock"
    void print();
    
};

#endif //MOCK_H
