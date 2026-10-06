#pragma once

#include "models/Product.hpp"
#include <optional>
#include <string>
#include <vector>

class ProductService {
    public:
        Product registerProduct(std::string name, double price, int stock);
        void unregisterProduct(const std::string& name);
        std::optional<Product> findProductByName(const std::string& name);
        std::optional<Product> findProductByID(const int& id);
        std::vector<Product> getAllProducts();
};