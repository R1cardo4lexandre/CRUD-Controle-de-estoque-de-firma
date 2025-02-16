//
// Created by bruno on 28/01/2025.
//

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

// Classe responsável pela manipulação do Banco de Dados
class Database {
private:
    std::map<std::string, int> stock; // Nome do item e sua quantidade
    std::vector<std::string> history; // Registro das operações feitas

    // Função para carregar os dados do arquivo para a memória
    void loadData();

    // Função para salvar os dados da memória para o arquivo
    void saveData() const;

public:
    // Construtor que carrega os dados ao iniciar
    Database();

    // Adiciona um novo item ao estoque
    void addItem(const std::string& name, int quantity);

    // Retira uma determinada quantidade do estoque
    void removeItem(const std::string& name, int quantity);

    // Exibe o estoque
    void showData() const;

    // Exibe o histórico das operções
    void showHistory() const;
};

#endif //DATABASE_H
