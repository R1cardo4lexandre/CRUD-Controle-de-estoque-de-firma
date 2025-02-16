//
// Created by bruno on 25/01/2025.
//

#include "Database.h"
#include <iostream>

void showMenu() {
    std::cout << "\n--- Sistema de Controle de Estoque ---\n";
    std::cout << "1. Adicionar peça\n";
    std::cout << "2. Retirar peça\n";
    std::cout << "3. Mostrar estoque\n";
    std::cout << "4. Mostrar histórico de operações\n";
    std::cout << "5. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int main() {
    Database db;
    int select;

    do {
        showMenu();
        std::cin >> select;

        switch (select) {
            case 1: {
                std::cout << "Nome do item: ";
                std::cin.ignore();
                std::getline(std::cin, Database.itemName);
                std::cout << "Quantidade: ";
                std::cin.ignore();
                std::cin >> Database.quantity;
                db.addItem(Database.itemName, Database.quantity);
                std::cout << "Item adicionado com sucesso!\n";
                break;
            }
            case 2: {
                std::string itemName;
                int quantity;
                std::cout << "Nome do item: ";
                std::cin.ignore();
                std::getline(std::cin, itemName);
                std::cout << "Quantidade retirada: ";
                std::cin.ignore();
                std::cin >> quantity;
                if (db.removeItem(Database.itemName, quantity)) {
                    std::cout << "Item removido com sucesso!\n";
                }
                break;
            }
            case 3: {
                db.showData();
                break;
            }
            case 4: {
                db.showHistory();
                break;
            }
            case 5: {
                std::cout << "Saindo do programa...\n";
                break;
            }
            default:
                std::cout << "Opção inválida!\n";
        }
    } while (select != 5);

    return 0;
}