#include "Component.h"

Component::Component(){}

std::string Component::getName(){ return name; }
std::string Component::getType(){ return type; }
std::string Component::getDescription(){ return description; }

void Component::setName(std::string name) { this->name = name; }
void Component::setType(std::string type) { this->name = type; }
void Component::setDescription(std::string description) { this->name = description; }
