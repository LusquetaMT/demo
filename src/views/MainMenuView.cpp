#include <iostream>
#include <string>
#include "views/MainMenuView.hpp"

void MainMenuView::showMenu() const {
    std::cout << "\n";
    std::cout << "====================================\n";
    std::cout << "        SUPERMARKET SYSTEM\n";
    std::cout << "====================================\n";
    std::cout << "\n";
    std::cout << "  [1] Registrar produto\n";
    std::cout << "  [2] Consultar produto por nome\n";
    std::cout << "  [3] Consultar produto por ID\n";
    std::cout << "  [4] Remover produto\n";
    std::cout << "  [0] Sair";
    std::cout << "\n";
    std::cout << "------------------------------------\n";
};

int MainMenuView::askCommand() {
    int command;
    std::cout << "Digite uma opcao: ";
    
    if (!(std::cin >> command)) {
        return -1;
    };

    return command;
};