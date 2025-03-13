#include "Repository.h"

std::vector<Travel> Repository::travels;

Repository::Repository(){}

Repository::~Repository() {

    std::cout << "Deletado com sucesso" << std::endl;
}

void Repository::insert(const Travel& t) {

   travels.emplace_back(t);
}

void Repository::deleteTravel(Travel t) {

    for (auto i = travels.begin(); i < travels.end(); i++) {

        if (i.base()->equals(t)) {
            travels.erase(i);
            break;
        }
    }
}

std::vector <Travel> Repository::getAll() {

    return travels;
}
