#include "Mock.h"

std::vector<Travel> Mock::travelMocks(3);
std::vector<float> Mock::floatMocks = {61.25f, 25.96f, 9.83f, 4.23f, 5.04f, 47.59f, 5.93f, 82.82f, 5.60f};
std::vector<std::string> Mock::stringMocks1 = {"Baixa da Égua", "Casa do caralho", "Quinto dos inferno"};
std::vector<std::string> Mock::stringMocks2 = {"palco", "house mix", "telão"};
std::vector<int> Mock::dateMocks = {1,2,3,4,5,6,7,8,9};

Mock::Mock () {};

void Mock::initMock() {

    for (int i = 0; i < travelMocks.size(); i++) {

        StageSize size = StageSize(floatMocks[i],floatMocks[i+1],floatMocks[i+2]);
        StageStructure structure = StageStructure(stringMocks2[i]);
        structure.setSize(size);
        travelMocks[i].setStructure(structure);
        travelMocks[i].setLocation(stringMocks1[i]);
        travelMocks[i].setStartDate(dateMocks[i], dateMocks[i+1], dateMocks[i+2]);
        travelMocks[i].setFinalDate(dateMocks[i+2], dateMocks[i], dateMocks[i+1]);
    }
}
