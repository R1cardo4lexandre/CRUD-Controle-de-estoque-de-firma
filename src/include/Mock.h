#ifndef MOCK_H
#define MOCK_H

#include <vector>
#include "Travel.h"

//Classe criada para realização de testes

class Mock {

    private:
    static std::vector<Travel> travelmocks;
    static std::vector<float> floatmocks;
    static std::vector<std::string> stringmocks1;
    static std::vector<std::string> stringmocks2;
    static std::vector<int> datemocks;

    public:
    Mock ();
    static void initMock();
    
};

#endif //MOCK_H
