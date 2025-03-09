//
// Created by bruno on 08/03/2025.
//


#include "Databasenew.h"
#include <iostream>
#include <fstream>

// Construtor que define o caminho do arquivo
Database::Database(const std::string& path) : filePath(path) {}

// Código para escrita em binário
template <typename T>
void Database::writeData(const T& data) {
    std::ofstream file(filePath, std::ios::binary | std::ios::trunc);
    if (!file) {
        std::cerr << "Erro: Não foi possível abrir o arquivo para escrita!\n";
        return;
    }
    file.write(reinterpret_cast<const char*>(&data), sizeof(T));
    file.close();
}

// Código para leitura em binário
template <typename T>
void Database::readData(T& data) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Erro: Não foi possível abrir o arquivo para leitura!\n";
        return;
    }
    file.read(reinterpret_cast<char*>(&data), sizeof(T));
    file.close();
}