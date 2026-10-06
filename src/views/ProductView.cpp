#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <vector>

#include "views/ProductView.hpp"
#include "models/Product.hpp"
#include "utils/TimeUtils.hpp"
#include "utils/StringUtils.hpp"

int ProductView::askConfirm() {
    std::cout << "Deseja confirmar as informacoes? (s/n): ";

    char confirm;
    std::cin >> confirm;

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );

    switch (std::tolower(static_cast<unsigned char>(confirm))) {
        case 's':
            return 1;

        case 'n':
            return -1;

        default:
            return 0;
    }
}

std::string ProductView::askName() {
    std::cout << "Digite o nome do produto: ";

    std::string name;
    std::getline(std::cin >> std::ws, name);

    return name;
}

bool ProductView::askRepeat(const std::string& msg) {
    std::cout << msg;

    char confirm;
    std::cin >> confirm;

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(),
        '\n'
    );

    return std::tolower(static_cast<unsigned char>(confirm)) == 's';
}

int ProductView::askInitialStock() {
    while (true) {
        std::cout << "Digite o estoque inicial: ";

        int stock;

        if (std::cin >> stock) {
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            return stock;
        }

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        showError("O estoque deve ser um numero inteiro.");
    }
}

double ProductView::askPrice() {
    while (true) {
        std::cout << "Digite o preco: ";

        double price;

        if (std::cin >> price) {
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            return price;
        }

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        showError("O preco deve ser um numero.");
    }
}

int ProductView::askID() {
    while (true) {
        std::cout << "Digite o ID: ";

        int id;

        if (std::cin >> id) {
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            return id;
        }

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        showError("O preco deve ser um numero.");
    }
}

void ProductView::showRegisterMenu() const {
    std::cout << "\n";
    std::cout << "====================================\n";
    std::cout << "        REGISTRAR PRODUTO\n";
    std::cout << "====================================\n";
    std::cout << "\n";
    std::cout << "Informe os dados do produto abaixo.\n";
    std::cout << "\n";
}

void ProductView::showListMenu() const {
    std::cout << "\n";
    std::cout << "====================================\n";
    std::cout << "        CONSULTAR PRODUTO\n";
    std::cout << "====================================\n";
    std::cout << "\n";
    std::cout << "Informe o ID ou nome do produto.\n";
    std::cout << "\n";
}

void ProductView::showProduct(const Product& product) const {
    std::cout << "\n";
    std::cout << "====================================\n";
    std::cout << "      INFORMACOES DO PRODUTO\n";
    std::cout << "====================================\n";
    std::cout << "ID: " << product.getId() << '\n';
    std::cout << "Nome: " << product.name << '\n';
    std::cout << "Preco: R$ " << product.price << '\n';
    std::cout << "Estoque: " << product.stock << '\n';
    std::cout << "Criado em: "
              << TimeUtils::formatTimestamp(product.getCreatedAt())
              << '\n';
    std::cout << "====================================\n\n";
}

void ProductView::showError(const std::string& msg) const {
    std::cout << "\n[ERRO] " << msg << "\n\n";
}

void ProductView::showWarn(const std::string& msg) const {
    std::cout << "\n[AVISO] " << msg << "\n\n";
}

void ProductView::showProductNames(const std::vector<std::string>& names) const {
    std::string formatted = StringUtils::join(names, ", ");
    std::cout << "Produtos registrados: " << '\"' << formatted << '\"' << "\n";
}