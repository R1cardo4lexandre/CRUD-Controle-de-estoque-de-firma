#ifndef TRAVEL_H
#define TRAVEL_H

#include <iostream>
#include <chrono>
#include "StageStructure.h"
#include "date.h"

/*Esta classe será usada para registro de viagens de trabalho.
  - Os atributos stageStructure e location referem-se, respectivamente, às estruturas que
    serão montadas e o local da montagem.
  - Os atributos referentem ao tempo são para definir a data inicial e final da montagem.*/

// TODO: precisa mover as definições para o arquivo-fonte
class Travel {

    StageStructure structure;
    std::string location;
    date::year_month_day startDate;
    date::year_month_day finalDate;

    public:
    Travel (){};

    //get e set do atributo location
    std::string getLocation(){return location;};
    void setLocation(std::string location){this->location = location;};

    //get e set do atributo startDate
    date::year_month_day getStartDate(){return startDate;};
    void setStartDate(int y, int m, int d) {this->startDate = date::year{y}/m/d;};

    //get e set do atributo finalDate
    date::year_month_day getFinalDate(){return finalDate;};
    void setFinalDate(int y, int m, int d) {this->finalDate = date::year{y}/m/d;};

    //operador de acesso para a classe StageStructure
    StageStructure& getStructure(){return structure;};
    void setStructure(StageStructure structure){this->structure = structure;};

};

#endif //TRAVEL_H
