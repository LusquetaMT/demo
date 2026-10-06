#include <iostream>

#include "controllers/ProductController.hpp"
#include "views/ProductView.hpp"
#include "services/ProductService.hpp"
#include "models/Product.hpp"
#include <string>
#include <vector>

ProductView productView;
ProductService productService;

void ProductController::unregisterProduct() {
    while (true) {
        this->listProductNames();
        std::string name = productView.askName();
        int confirm = productView.askConfirm();

        switch (confirm) {
            case 1:
                try {
                    productService.unregisterProduct(name);
                    std::cout << "Produto removido com sucesso!" << "\n";
                    
                    bool doRepeat = productView.askRepeat(
                        "Deseja remover outro produto? (s/n): "
                    );
                    
                    if (!doRepeat) {
                        return;
                    }
                }
                catch (const std::exception& e) {
                    productView.showError(e.what());

                    bool doRepeat = productView.askRepeat(
                        "Deseja tentar novamente? (s/n): "
                    );

                    if (!doRepeat) {
                        return;
                    }
                }
            
            case 0:
                // Tenta preencher os dados novamente
                break;

            case -1:
                // Volta ao menu anterior
                return;
        };
    }
}

void ProductController::editProduct() {
    this->listProductNames();   
}

void ProductController::listProductNames() {
    try {
        std::vector<Product> products = productService.getAllProducts();
        if (size(products) == 0) {
            productView.showWarn("Nenhum produto foi encontrado no sistema");
            return;
        };

        std::vector<std::string> names;
        for (const Product& product : products) {
            names.push_back(product.name);
        }

        productView.showProductNames(names);
    }
    catch (const std::exception& e) {
        productView.showError(e.what());
    }
};

void ProductController::findProductByID() {
    while (true) {
        int id = productView.askID();

        try {
            std::optional<Product> product = productService.findProductByID(id);
            if (product.has_value()) {
                productView.showProduct(product.value());
            } else {
                productView.showError("Esse produto nao foi encontrado no sistema");
            };
            
            bool doRepeat = productView.askRepeat(
                "Deseja procurar outro produto? (s/n): "
            );
            
            if (!doRepeat) {
                return;
            }
        }
        catch (const std::exception& e) {
            productView.showError(e.what());

            bool doRepeat = productView.askRepeat(
                "Deseja tentar novamente? (s/n): "
            );

            if (!doRepeat) {
                return;
            }
        }
    };
};

void ProductController::findProductByName() {
    while (true) {
        this->listProductNames();
        std::string name = productView.askName();

        try {
            std::optional<Product> product = productService.findProductByName(name);
            if (product.has_value()) {
                productView.showProduct(product.value());
            } else {
                productView.showError("Esse produto nao foi encontrado no sistema");
            };
            
            bool doRepeat = productView.askRepeat(
                "Deseja procurar outro produto? (s/n): "
            );
            
            if (!doRepeat) {
                return;
            }
        }
        catch (const std::exception& e) {
            productView.showError(e.what());

            bool doRepeat = productView.askRepeat(
                "Deseja tentar novamente? (s/n): "
            );

            if (!doRepeat) {
                return;
            }
        }
    };
};

void ProductController::registerProduct() {
    while (true) {
        productView.showRegisterMenu();

        std::string name = productView.askName();
        int initialStock = productView.askInitialStock();
        double price = productView.askPrice();
        int confirm = productView.askConfirm();

        switch (confirm) {
            case 1:
                try {
                    Product newProduct = productService.registerProduct(
                        name,
                        price,
                        initialStock
                    );

                    productView.showProduct(newProduct);

                    bool doRepeat = productView.askRepeat(
                        "Deseja registrar um novo produto? (s/n): "
                    );

                    if (!doRepeat) {
                        return;
                    }
                }
                catch (const std::exception& e) {
                    productView.showError(e.what());

                    bool doRepeat = productView.askRepeat(
                        "Deseja tentar novamente? (s/n): "
                    );

                    if (!doRepeat) {
                        return;
                    }
                }

                break;

            case 0:
                // Tenta preencher os dados novamente
                break;

            case -1:
                // Volta ao menu anterior
                return;
        }
    }
}