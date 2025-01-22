#ifndef TRAVEL_H
#define TRAVEL_H

#include "StageStructure.h"
#include "Time.h"

/*Esta classe será usada para registro de viagens de trabalho.
  - Os atributos stageStructure e location referem-se, respectivamente, às estruturas que
    serão montadas e o local da montagem.
  - Os atributos referentem ao tempo são para definir a data inicial e final da montagem.*/

class Travel {

    StageStructure stageStructure;
    std::string location;
    Time startDate;
    Time finalDate;

};

#endif //TRAVEL_H
