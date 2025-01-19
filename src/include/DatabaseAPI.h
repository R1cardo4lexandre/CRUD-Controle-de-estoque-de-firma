//
// Created by bruno on 13/01/2025.
//
#ifndef DATABASE_API_H
#define DATABASE_API_H

#include <string>
#include <map>

//Criação da Classe virtual do Banco de Dados para testes durente a implementação

class DatabaseAPI {
public:
    virtual std::map<std::string, std::string> read(const std::string& tableName) const = 0;
    virtual void write(const std::string& tableName, const std::map<std::string, std::string>& data) = 0;
    virtual ~DatabaseAPI() = default;
};

#endif // DATABASE_API_H

