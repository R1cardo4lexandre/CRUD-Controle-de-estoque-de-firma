#ifndef STAGE_SIZE_H
#define STAGE_SIZE_H

#include <iostream>

/*Esta classe refere-se ao tamanho das estruturas que serão feitas na montagem.*/

// TODO: É necessário mudar as definições das funções pros arquivos-fonte
// TODO: esse arquivo vai dar erro na compilação, faltam ponto e vírgula em vários lugares
class StageSize {

    float width;
    float length;
    float height;

    public:
    StageSize (){};

    StageSize(float width, float length, float height) : width(width), length(length), height(height) {}

    float getWidth() { return width; }
    float getLength() { return length; }
    float getHeight() { return height; }
    void setWidth(float width) {this->width = width;};
    void setLength(float length) {this->length = length;};
    void setHeight(float height) {this->height = height;};


};

#endif //STAGE_SIZE_H
