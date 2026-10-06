#include <iostream>
#include "views/MainMenuView.hpp"
#include "controllers/ProductController.hpp"

using namespace std;

int main() {
    MainMenuView menu;
    ProductController productController;

    while (true) {
        menu.showMenu();
        int command = menu.askCommand();
        
        switch (command) {
            case 1:
                productController.registerProduct();
                break;
            
            case 2:
                productController.findProductByName();
                break;
            
            case 3:
                productController.findProductByID();
                break;

            case 4:
                productController.unregisterProduct();
                break;

            case 0:
                return 0;
            
            case -1:
                std::cout << "Comando invalido, tente novamente";
        };
    };

    return 0;
};