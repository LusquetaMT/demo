#pragma once

#include <string>

class ProductController {
    public:
        void registerProduct();
        void findProductByName();
        void findProductByID();
        void listProductNames();
        void editProduct();
        void unregisterProduct();
};