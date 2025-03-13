#include "Travel.h"

Travel::Travel() : structure(StageStructure()), startDate("31/12/1900"), finalDate("31/12/1900") {
}

//get e set do atributo location
std::string Travel::getLocation(){return location;}
void Travel::setLocation(std::string location){this->location = location;}

//get e set do atributo startDate
std::string Travel::getStartDate(){return startDate;}
void Travel::setStartDate(std::string startDate) {this->startDate = startDate;}

//get e set do atributo finalDate
std::string Travel::getFinalDate(){return finalDate;}
void Travel::setFinalDate(std::string finalDate) {this->finalDate = finalDate;}

//operador de acesso para a classe StageStructure
StageStructure Travel::getStructure(){return structure;}
void Travel::setStructure(StageStructure structure){this->structure = structure;}

bool Travel::equals(Travel t) {

    if (location == t.location && startDate == t.startDate && finalDate == t.finalDate
        && structure.equals(structure)) {
        return true;
    }
    return false;
}