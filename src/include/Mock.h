#ifndef MOCK_H
#define MOCK_H

#include "Travel.h"

#include <vector>

//Classe criada para realização de testes

class Mock {

public:
    Mock ();

    static void initMock();

private:
    static std::vector<Travel> travelMocks;
    static std::vector<float> floatMocks;
    static std::vector<std::string> stringMocks1;
    static std::vector<std::string> stringMocks2;
    static std::vector<int> dateMocks;
    
};

#endif //MOCK_H
