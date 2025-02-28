#include "Mock.h"

std::vector<Travel> Mock::travelmocks(3);
std::vector<float> Mock::floatmocks = {61.25f, 25.96f, 9.83f, 4.23f, 5.04f, 47.59f, 5.93f, 82.82f, 5.60f};
std::vector<std::string> Mock::stringmocks1 = {"Baixa da Égua", "Casa do caralho", "Quinto dos inferno"};
std::vector<std::string> Mock::stringmocks2 = {"palco", "house mix", "telão"};
std::vector<int> Mock::datemocks = {1,2,3,4,5,6,7,8,9};

Mock::Mock () {};

void Mock::initMock() {

    for (int i = 0; i < travelmocks.size(); i++) {

        StageSize size = StageSize(floatmocks[i],floatmocks[i+1],floatmocks[i+2]);
        StageStructure structure = StageStructure(stringmocks2[i]);
        structure.setSize(size);
        travelmocks[i].setStructure(structure);
        travelmocks[i].setLocation(stringmocks1[i]);
        travelmocks[i].setStartDate(datemocks[i], datemocks[i+1], datemocks[i+2]);
        travelmocks[i].setFinalDate(datemocks[i+2], datemocks[i], datemocks[i+1]);
    }
}
