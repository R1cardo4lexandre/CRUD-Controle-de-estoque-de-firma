#ifndef STAGE_STRUCTURE_H
#define STAGE_STRUCTURE_H

#include "StageSize.h"

#include <string>

/*Esta classe refere-se às estruturas que serão feitas na montagem, como palcos ou house mixes.
  - O atributo type é para definir qual o tipo de estrutura, como os exemplos citados acima.
  - O atributo size é para referenciar o tamanho da estrutura.*/

class StageStructure {

    std::string type;
    StageSize size;

};

#endif //STAGE_STRUCTURE_H
