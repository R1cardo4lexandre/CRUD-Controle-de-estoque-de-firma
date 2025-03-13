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

    static std::vector<Travel> search(std::string);

    static int getID(Travel);

    static void update(Travel, int);

    static void save();


private:

    static std::vector<Travel> travels;
    static std::string tableName;
};

#endif //REPOSITORY_H
