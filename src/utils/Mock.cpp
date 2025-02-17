#include "../include/Mock.h"

Mock::Mock () {
    travel.emplace_back(Travel());
    travel.emplace_back(Travel());
    travel.emplace_back(Travel());
};

void Mock::read() {
    for (int i = 0; i < 3; i++) {
        travel[i].setLocation("Baixa da Égua");
        travel[i].setStartDate(2007,3,31);
        travel[i].setFinalDate(2008,3,31);
        travel[i].getStructure().setType("Palco");
        travel[i].getStructure().getSize().setWidth(12);
        travel[i].getStructure().getSize().setLength(10);
        travel[i].getStructure().getSize().setHeight(8);
    }
}

void Mock::print() {

    for (int i=0; i<3; i++) {
        cout << "Local da viagem: " << travel[i].getLocation() << endl << "Tipo da estrutura: " <<
            travel[i].getStructure().getType() << endl << "Tamanho: " <<
            travel[i].getStructure().getSize().getWidth() << " " <<
            travel[i].getStructure().getSize().getLength() << " " <<
            travel[i].getStructure().getSize().getHeight() << endl;
    }
}


