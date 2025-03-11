//
// Created by bruno on 13/01/2025.
//
#ifndef DATABASE_API_H
#define DATABASE_API_H

#include <map>
#include <string>
#include <vector>

/*
    Criação da Classe virtual do Banco de Dados para testes durente a implementação
*/

class DatabaseAPI {
public:
    virtual std::vector<std::map<std::string, std::string>> read(const std::string& tableName) const = 0;
    virtual void write(const std::string& tableName, const std::vector<std::map<std::string, std::string>>& data) = 0;
    virtual ~DatabaseAPI() = default;
    virtual void clear() = 0;
};

#endif // DATABASE_API_H
