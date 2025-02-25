#include "../include/Travel.h"

Travel::Travel() {}

//get e set do atributo location
std::string Travel::getLocation(){return location;}
void Travel::setLocation(std::string location){this->location = location;}

//get e set do atributo startDate
date::year_month_day Travel::getStartDate(){return startDate;}
void Travel::setStartDate(int y, int m, int d) {this->startDate = date::year{y}/m/d;}

//get e set do atributo finalDate
date::year_month_day Travel::getFinalDate(){return finalDate;}
void Travel::setFinalDate(int y, int m, int d) {this->finalDate = date::year{y}/m/d;}

//operador de acesso para a classe StageStructure
StageStructure Travel::getStructure(){return structure;}
void Travel::setStructure(StageStructure structure){this->structure = structure;}