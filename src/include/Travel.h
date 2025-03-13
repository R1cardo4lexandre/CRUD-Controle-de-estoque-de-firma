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
    void setLocation(std::string);

    date::year_month_day getStartDate();
    void setStartDate(int, int, int);

    date::year_month_day getFinalDate();
    void setFinalDate(int, int, int);

    StageStructure getStructure();
    void setStructure(StageStructure);

    bool equals(Travel);

private:
    std::string location;
    StageStructure structure;
    date::year_month_day startDate;
    date::year_month_day finalDate;

};

#endif //TRAVEL_H
