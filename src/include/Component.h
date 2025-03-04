#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>

/*Esta classe refere-se aos componentes utilizados na montagem das estruturas, sejam peças
  como grids ou tablados, além de utilitários importantes como cintas e talhas.
  Seus atributos conferem ao objeto nome, tipo de componente e descrição do mesmo*/

class Component {

public:
    Component();

    std::string getName();
    std::string getType();
    std::string getDescription();

    void setName(std::string);
    void setType(std::string);
    void setDescription(std::string);

private:
    std::string name;
    std::string type;
    std::string description;
};

#endif //COMPONENT_H
