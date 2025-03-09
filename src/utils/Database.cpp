//
// Created by bruno on 28/01/2025.
//

#include "Database.h"
#include <iostream>

// Construtor que carrega os dados do estoque para a memória
Database::Database() {
    loadData();
}

// Função para carregar os dados do arquivo
void Database::loadData() {
    std::ifstream file("estoque.txt"); // Abre o arquivo do estoque para leitura
    if (!file) {
        std::cerr << "Erro: Nenhum arquivo encontrado!\n";
        std::ofstream newfile("estoque.txt"); // Cria um arquivo vazio
            if (newfile) {
              newfile << "Nome, Quantidade\n"; // Garante que o arquivo já tenha inicialização
              newfile.close();
            }
        return;
    }

    stock.clear(); // Limpa os dados atuais antes de carregar o arquivo
    std::string name;
    int quantity;
    while (file >> name >> quantity) {
      stock[name] = quantity;
    }
    file.close();
}

// Função que salva os dados do estoque no arquivo
void Database::saveData() const {
    std::ofstream file("estoque.txt");
    if (!file) {
      std::cerr << "Erro: Não foi possível salvar os dados!\n";
      return;
    }
    for (const auto& [name, quantity] : stock) {
      file << name << " " << quantity << "\n";
    }
    file.close();

}

// Adiciona um novo item ou aumenta a quantidade
void Database::addItem(const std::string name, int quantity) {
    stock[name] += quantity;
    history.push_back("Adicionado: " + name + " (" + std::to_string(quantity) + ")");
    saveData();
}

// Retira quantidades de itens
bool Database::removeItem(const std::string name, int quantity) {
    auto it = stock.find(name);
    if (it == stock.end()) {
      std::cerr << "Erro: Item não encontrado!\n";
      return false;
    }
    if (it->second < quantity) {
      std::cerr << "Erro: Quantidade insuficiente no estoque!\n";
      return false;
    }

    it->second -= quantity; // Reduz a quantidade do item
    history.push_back("Retirado: " + name + " (" + std::to_string(quantity) + ")");

    if (it->second == 0) {
        std::cout << "Aviso: O item '" << name << "' está com estoque zerado.\n";
    }

    saveData();
    return true;

}

// Exibe o estoque atual
void Database::showData() const {
    std::cout << "Estoque atual:\n";
    for (const auto& [name, quantity] : stock) {
      std::cout << "- " << name << ": " << quantity << "\n";
    }
}

// Exibe o histórico de operações
void Database::showHistory() const {
    std::cout << "Histórico de operações:\n";
    for (const auto& entry : history) { // "Variavel" entry é criada para armazenar os dados e ser exibida
      std::cout << entry << "\n";
    }
}