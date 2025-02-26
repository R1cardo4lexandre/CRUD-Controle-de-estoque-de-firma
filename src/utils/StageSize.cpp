// TODO: remover esse caminho de arquivo, dever ser somente #include "../include/StageSize.h".
// TODO: checar os outros arquivos e ver se há algum include com esse probleam
#include "../include/StageSize.h"

StageSize::StageSize(){}

StageSize::StageSize(float w, float l, float h) {
    width = w;
    length = l;
    height = h;
}

float StageSize::getWidth() {return width;}
float StageSize::getLength() {return length;}
float StageSize::getHeight() {return height;}

void StageSize::setWidth(float width) {this->width = width;}
void StageSize::setLength(float length) {this->length = length;}
void StageSize::setHeight(float height) {this->height = height;}
