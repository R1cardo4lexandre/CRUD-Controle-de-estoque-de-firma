#include "StageSize.h"

StageSize::StageSize() : width(0.0f), length(0.0f), height(0.0f) {}

StageSize::StageSize(float w, float l, float h) : width(w), length(l), height(h) {}

float StageSize::getWidth() {return width;}
void StageSize::setWidth(float width) {this->width = width;}

float StageSize::getLength() {return length;}
void StageSize::setLength(float length) {this->length = length;}

float StageSize::getHeight() {return height;}
void StageSize::setHeight(float height) {this->height = height;}
