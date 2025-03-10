#include "Component.h"

Component::Component(){}

std::string Component::getName(){ return name; }
void Component::setName(std::string name) { this->name = name; }

std::string Component::getType(){ return type; }
void Component::setType(std::string type) { this->name = type; }

std::string Component::getDescription(){ return description; }
void Component::setDescription(std::string description) { this->name = description; }
