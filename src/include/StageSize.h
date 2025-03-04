#ifndef STAGE_SIZE_H
#define STAGE_SIZE_H

/*Esta classe refere-se ao tamanho das estruturas que serão feitas na montagem.*/

class StageSize {

public:
    StageSize();

    StageSize(float, float, float);

    float getWidth();
    float getLength();
    float getHeight();

    void setWidth(float);
    void setLength(float);
    void setHeight(float);

private:
    float width;
    float length;
    float height;

};

#endif //STAGE_SIZE_H
