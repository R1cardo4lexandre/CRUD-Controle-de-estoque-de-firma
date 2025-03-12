#include "StageStructure.h"

StageStructure::StageStructure() : size(StageSize()) {}

StageStructure::StageStructure(std::string t) {
    type = t;
}

std::string StageStructure::getType(){return type;}
void StageStructure::setType(std::string type){this->type = type;};

StageSize StageStructure::getSize(){return size;};
void StageStructure::setSize(StageSize size){this->size = size;};