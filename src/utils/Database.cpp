//
// Created by bruno on 28/01/2025.
//

#include "StringUtils.h"
#include "Database.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <regex>

std::string Database::COLUMN_SEPARATOR = "@3*&!";

std::string Database::TABLE_SEPARATOR = "endtable";

// Construtor que carrega os dados do estoque para a memória
Database::Database() : DB_FILE_NAME("database.txt") {
}

Database::~Database() = default;


std::vector<std::map<std::string, std::string> > Database::read(const std::string &tableName) const {
    std::ifstream dbfile(DB_FILE_NAME); // Abre o arquivo do estoque para leitura
    std::vector<std::map<std::string, std::string> > data;
    std::vector<std::string> keys;

    if (dbfile) {
        std::string line;
        bool addRow = false;
        std::vector<std::string> rows;

        while (std::getline(dbfile, line)) {
            if (line == tableName) {
                addRow = true;
                continue;
            } else if (line == TABLE_SEPARATOR) {
                addRow = false;
                continue;
            }

            if (addRow) rows.emplace_back(line);
        }

        if (rows.size() > 1) {
            keys = StringUtils::split(rows[0], COLUMN_SEPARATOR);


            for (int i = 1; i < rows.size(); i++) {
                std::map<std::string, std::string> row;

                std::vector<std::string> split = StringUtils::split(rows[i], COLUMN_SEPARATOR);

                for (int i = 0; i < keys.size(); ++i) row.insert({keys[i], split[i]});

                data.emplace_back(row);
            }
        }
    }

    return data;
}

// Função que salva os dados do estoque no arquivo
void Database::write(const std::string &tableName, const std::vector<std::map<std::string, std::string> > &data) {
    std::ofstream dbfile(DB_FILE_NAME, std::ios::app);
    std::vector<std::string> keys;

    if (!dbfile) {
        std::cerr << "Erro: Não foi possível salvar os dados!\n";
        return;
    }

    dbfile << tableName << std::endl;

    for (auto m: data[0]) keys.emplace_back(m.first);

    dbfile << StringUtils::join(keys, COLUMN_SEPARATOR) << std::endl;

    for (auto d: data) {
        std::vector<std::string> row;

        for (std::string k: keys) row.emplace_back(d.at(k));

        dbfile << StringUtils::join(row, COLUMN_SEPARATOR) << std::endl;
    }

    dbfile << TABLE_SEPARATOR << std::endl << std::endl;

    dbfile.close();
}

void Database::clear() {
    std::ofstream dbfile(DB_FILE_NAME);

    dbfile << "";
}
