#include "Mock.h"

std::vector<Travel> Mock::travelMocks(3);
std::vector<float> Mock::floatMocks = {61.25f, 25.96f, 9.83f, 4.23f, 5.04f, 47.59f, 5.93f, 82.82f, 5.60f};
std::vector<std::string> Mock::stringMocks1 = {"Lugar Teste 1", "Lugar Teste 2", "Lugar Teste 3"};
std::vector<std::string> Mock::stringMocks2 = {"palco", "house mix", "telão"};
std::vector<std::string> Mock::dateMocks1 = {"12/34/4562","12/34/4562","12/34/4562"};
std::vector<std::string> Mock::dateMocks2 = {"14/03/2130","14/03/2130","14/03/2130"};


Mock::Mock () {};

void Mock::initMock() {

    for (int i = 0; i < travelMocks.size(); i++) {

        StageSize size = StageSize(floatMocks[i],floatMocks[i+1],floatMocks[i+2]);
        StageStructure structure = StageStructure(stringMocks2[i]);
        structure.setSize(size);
        travelMocks[i].setStructure(structure);
        travelMocks[i].setLocation(stringMocks1[i]);
        travelMocks[i].setStartDate(dateMocks1[i]);
        travelMocks[i].setFinalDate(dateMocks2[i]);
    }
}

Travel Mock::getTravelMock (int i) {
    return travelMocks[i];
}
