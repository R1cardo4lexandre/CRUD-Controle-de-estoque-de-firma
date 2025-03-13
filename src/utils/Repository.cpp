#include "Repository.h"

#include "ApplicationManager.h"
#include "Mock.h"
#include <map>
#include <iostream>

std::vector<Travel> Repository::travels;
std::string Repository::tableName = "Travels";

Repository::Repository() {

    for (auto i : ApplicationManager::database->read(tableName)) {

        Travel travel;

        auto width = std::stof(i["width"]);
        auto length = std::stof(i["length"]);
        auto height = std::stof(i["height"]);

        StageSize size = StageSize(width, length, height);

        travel.setLocation(i["location"]);

        StageStructure structure = StageStructure(i["structure"]);

        structure.setSize(size);

        travel.setStructure(structure);

        travel.setStartDate(i["StartDate"]);

        travel.setFinalDate(i["FinalDate"]);

        travels.emplace_back(travel);
    }


}

Repository::~Repository() {}

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

std::vector<Travel> Repository::search(std::string srch) {

    std::vector<Travel> t;

    for (Travel travel : travels) {

        if (travel.getLocation().find(srch) != std::string::npos) {

            t.emplace_back(travel);
        }
    }

    return t;
}

std::vector <Travel> Repository::getAll() {

    return travels;
}

int Repository::getID(Travel t) {

    for (int i = 0; i < travels.size(); i++) {

        if (travels[i].equals(t)) {
            return i;
        }
    }

    return -1;
}

Travel Repository::update(Travel t, int pos) {

    travels[pos] = t;
}

void Repository::save() {

    if (travels.size() == 0) { return; }
    std::map<std::string, std::string> travel;
    std::vector<std::map<std::string, std::string>> rows;
    for (auto i = travels.begin(); i < travels.end(); i++) {

        travel["location"] = i.base()->getLocation();
        travel["structure"] = i.base()->getStructure().getType();
        travel["width"] = std::to_string(i.base()->getStructure().getSize().getWidth());
        travel["length"] = std::to_string(i.base()->getStructure().getSize().getLength());
        travel["height"] = std::to_string(i.base()->getStructure().getSize().getHeight());
        travel["StartDate"] = i.base()->getStartDate();
        travel["FinalDate"] = i.base()->getFinalDate();

        rows.emplace_back(travel);
    }
    ApplicationManager::database->write(tableName, rows);
}
