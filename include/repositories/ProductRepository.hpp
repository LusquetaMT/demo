#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include <vector>

#include "models/Product.hpp"

using json = nlohmann::json;

class ProductRepository {
    public:
        int generateNextID();
        void registerProduct(const Product& product);
        void unregisterProduct(const std::string name);
        bool productExists(std::string name);

        std::optional<Product> getProductByName(std::string name);
        std::optional<Product> getProductByID(int id);
        std::vector<Product> getAllProducts();

    private:
        json productToJson(const Product& product);
        Product jsonToProduct(const json& data);
};