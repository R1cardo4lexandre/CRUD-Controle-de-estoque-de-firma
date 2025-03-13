#include "StageSize.h"

StageSize::StageSize(){}

StageSize::StageSize(float w, float l, float h) {
    width = w;
    length = l;
    height = h;
}

float StageSize::getWidth() {return width;}
void StageSize::setWidth(float width) {this->width = width;}

float StageSize::getLength() {return length;}
void StageSize::setLength(float length) {this->length = length;}

float StageSize::getHeight() {return height;}
void StageSize::setHeight(float height) {this->height = height;}

bool StageSize::equals(StageSize sz) {

    if (width == sz.width && length == sz.length && height == sz.height) {
        return true;
    }
    return false;
}
