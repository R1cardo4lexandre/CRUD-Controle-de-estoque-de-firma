#include "StageStructure.h"

StageStructure::StageStructure() {}

StageStructure::StageStructure(std::string t) {
    type = t;
}

std::string StageStructure::getType(){return type;}
StageSize StageStructure::getSize(){return size;};

void StageStructure::setType(std::string type){this->type = type;};
void StageStructure::setSize(StageSize size){this->size = size;};