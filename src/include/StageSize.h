#ifndef STAGE_SIZE_H
#define STAGE_SIZE_H

/*Esta classe refere-se ao tamanho das estruturas que serão feitas na montagem.*/

class StageSize {

    float width;
    float length;
    float height;

    public:
    StageSize();

    StageSize(float, float, float);

    float getWidth();
    float getLength();
    float getHeight();

    void setWidth(float);
    void setLength(float);
    void setHeight(float);

};

#endif //STAGE_SIZE_H
