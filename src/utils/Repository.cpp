#include "Repository.h"

Repository::Repository(){}

Repository::~Repository(){}

void Repository::insert(Travel t) {

   travels.emplace_back(t);
}

void Repository::del(Repository *r) {

    delete r;
}

