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

    static void insert(Travel);

    static void del(Repository*);

private:

    static std::vector<Travel> travels;
};

#endif //REPOSITORY_H
