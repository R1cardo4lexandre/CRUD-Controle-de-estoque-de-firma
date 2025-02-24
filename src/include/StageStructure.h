#ifndef STAGE_STRUCTURE_H
#define STAGE_STRUCTURE_H

#include <iostream>
#include "StageSize.h"

/*Esta classe refere-se às estruturas que serão feitas na montagem, como palcos ou house mixes.
  - O atributo type é para definir qual o tipo de estrutura, como os exemplos citados acima.
  - O atributo size é para referenciar o tamanho da estrutura.*/

// TODO: É necessário mudar as definições das funções pros arquivos-fonte.

class StageStructure {

    std::string type;
    StageSize size;

    public:
    StageStructure (){};
    StageStructure (std::string t) : type(t){};

    std::string getType(){return type;};
    void setType(std::string type){this->type = type;};
    StageSize& getSize(){return size;};
    void setSize(StageSize size){this->size = size;};

};

#endif //STAGE_STRUCTURE_H
