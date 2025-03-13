#ifndef TRAVEL_H
#define TRAVEL_H

#include "StageStructure.h"

/*Esta classe será usada para registro de viagens de trabalho.
  - Os atributos stageStructure e location referem-se, respectivamente, às estruturas que
    serão montadas e o local da montagem.
  - Os atributos referentem ao tempo são para definir a data inicial e final da montagem.*/

class Travel {

public:
    Travel ();

    std::string getLocation();
    void setLocation(std::string);

    std::string getStartDate();
    void setStartDate(std::string);

    std::string getFinalDate();
    void setFinalDate(std::string);

    StageStructure getStructure();
    void setStructure(StageStructure);

    bool equals(Travel);

private:
    std::string location;
    StageStructure structure;
    std::string startDate;
    std::string finalDate;

};

#endif //TRAVEL_H
