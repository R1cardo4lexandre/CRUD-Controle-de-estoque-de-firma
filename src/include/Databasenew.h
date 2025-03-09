//
// Created by bruno on 08/03/2025.
//

#ifndef DATABASENEW_H
#define DATABASENEW_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "DatabaseAPI.h"

#ifdef _WIN32
    #define DEFAULT_DB_PATH "C:\\temp\\database.bin"
#else
    #define DEFAULT_DB_PATH "/tmp/database.bin"
#endif

// Classe genérica para manipulação de arquivos de banco de dados
class Database : public DatabaseAPI {
private:
    std::string filePath; // Caminho do arquivo

public:
    // Construtor padrão, usa um caminho predefinido
    Database(const std::string& path = DEFAULT_DB_PATH) : filePath(path) {}

    // Escreve dados binários no banco de dados
    template <typename T>
    void writeData(const T& data) {
        std::ofstream file(filePath, std::ios::binary);
        if (!file) {
            std::cerr << "Erro: Não foi possível abrir o arquivo para escrita!\n";
            return;
        }
        file.write(reinterpret_cast<const char*>(&data), sizeof(T));
        file.close();
    }

    // Lê dados binários do banco e os retorna
    template <typename T>
    void readData(T& data) {
        std::ifstream file(filePath, std::ios::binary);
        if (!file) {
            std::cerr << "Erro: Não foi possível abrir o arquivo para leitura!\n";
            return;
        }
        file.read(reinterpret_cast<char*>(&data), sizeof(T));
        file.close();
    }
};

#endif //DATABASENEW_H
