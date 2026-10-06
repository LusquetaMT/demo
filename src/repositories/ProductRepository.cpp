#include "repositories/ProductRepository.hpp"
#include "models/Product.hpp"

#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>

using json = nlohmann::json;

int ProductRepository::generateNextID() {
    std::ifstream file("data/products.json");
    
    if (!file.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir data/products.json");
    };

    json products;
    file >> products;
    
    return products.size() + 1;
};

std::vector<Product> ProductRepository::getAllProducts() {
    std::vector<Product> allProducts;
    std::ifstream file("data/products.json");

    if (!file.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir data/products.json");
    };

    json products;
    file >> products;
    
    for (const auto& productJson : products) {
        allProducts.push_back(jsonToProduct(productJson));
    };

    return allProducts;
};

void ProductRepository::registerProduct(const Product& product) {
    json newJson = this->productToJson(product);
    
    std::ifstream file("data/products.json");

    if (!file.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir data/products.json");
    };

    json products;
    file >> products;

    file.close();

    products.push_back(newJson);

    std::ofstream output("data/products.json");
    output << products.dump(4);
};

std::optional<Product>ProductRepository::getProductByID(int id) {
    std::ifstream file("data/products.json");

    if (!file.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir data/products.json");
    };

    json products;
    file >> products;
    
    for (const auto& productJson : products) {
        if (productJson["id"] == id) {
            return jsonToProduct(productJson);
        }
    };

    return std::nullopt;
};

std::optional<Product>ProductRepository::getProductByName(std:: string name) {
    std::ifstream file("data/products.json");

    if (!file.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir data/products.json");
    };

    json products;
    file >> products;

    for (const auto& productJson : products) {
        if (productJson["name"] == name) {
            return jsonToProduct(productJson);
        }
    };

    return std::nullopt;
};

void ProductRepository::unregisterProduct(std::string name) {
    std::ifstream file("data/products.json");

    if (!file.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir data/products.json");
    };

    json products;
    file >> products;
    file.close();
    
    for (auto it = products.begin(); it != products.end(); ++it) {
        if ((*it)["name"] == name) {
            products.erase(it);

            std::ofstream output("data/products.json");

            if (!output.is_open()) {
                throw std::runtime_error("Nao foi possivel salvar products.json");
            }

            output << products.dump(4);
        }
    }
};

bool ProductRepository::productExists(std:: string name) {
    return this->getProductByName(name).has_value();
};

json ProductRepository::productToJson(const Product& product) {
    json productJson;
    
    productJson["id"] = product.getId();
    productJson["name"] = product.name;
    productJson["price"] = product.price;
    productJson["stock"] = product.stock;
    productJson["createdAt"] = product.getCreatedAt();

    return productJson;
};

Product ProductRepository::jsonToProduct(const json& data) {
    Product product(data["name"], data["price"], data["stock"], data["id"], data["createdAt"]);
    return product;
};