#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Database.h"
#include "Travel.h"

#include <vector>

//classe do repositório (esta descrição será atualizada)
class Repository {

public:

    Repository();

    ~Repository();

    static void insert(const Travel&);

    static void deleteTravel(Travel);

    static std::vector<Travel> getAll();



private:

    static std::vector<Travel> travels;
};

#endif //REPOSITORY_H
