//
// Created by bruno on 28/01/2025.
//

#ifndef DATABASE_H
#define DATABASE_H

#include "DatabaseAPI.h"

#include <map>
#include <string>
#include <vector>

/*
    Classe responsável pela manipulação do Banco de Dados
*/

class Database : public DatabaseAPI {
 */

public:
    // Construtor que carrega os dados ao iniciar
    Database();

    std::vector<std::map<std::string, std::string>> read(const std::string &tableName) const override;

    void write(const std::string &tableName, const std::vector<std::map<std::string, std::string>> &data) override;

    ~Database() override;

    void clear() override;

private:

    std::string DB_FILE_NAME;

    static std::string COLUMN_SEPARATOR;

    static std::string TABLE_SEPARATOR;
};

#endif //DATABASE_H
