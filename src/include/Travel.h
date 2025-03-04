#ifndef TRAVEL_H
#define TRAVEL_H

#include "StageStructure.h"
#include "date.h"

/*Esta classe será usada para registro de viagens de trabalho.
  - Os atributos stageStructure e location referem-se, respectivamente, às estruturas que
    serão montadas e o local da montagem.
  - Os atributos referentem ao tempo são para definir a data inicial e final da montagem.*/

class Travel {

public:
    Travel ();

    std::string getLocation();
    date::year_month_day getStartDate();
    date::year_month_day getFinalDate();
    StageStructure getStructure();

    void setLocation(std::string);
    void setStartDate(int, int, int);
    void setFinalDate(int, int, int);
    void setStructure(StageStructure);

private:
    std::string location;
    StageStructure structure;
    date::year_month_day startDate;
    date::year_month_day finalDate;

};

#endif //TRAVEL_H
