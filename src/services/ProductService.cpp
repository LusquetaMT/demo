#include <cmath>
#include <vector>

#include "models/Product.hpp"
#include "services/ProductService.hpp"
#include "exceptions/InvalidProductException.hpp"
#include "exceptions/DuplicatedProductException.hpp"
#include "exceptions/NotRegisteredProductException.hpp"
#include "repositories/ProductRepository.hpp"
#include "utils/TimeUtils.hpp"

ProductRepository productRepository;

Product ProductService::registerProduct(std::string name, double price, int stock) {
    if (price <= 0) {
        throw InvalidProductException("Preco deve ser maior do que zero");
    };

    if (stock < 0) {
        throw InvalidProductException("O estoque inicial não deve ser negativo");
    };

    if (productRepository.productExists(name)) {
        throw DuplicatedProductException("Esse produto ja existe no sistema");
    };

    int newID = productRepository.generateNextID();
    long long createdAt = TimeUtils::generateTimestamp();
    Product newProduct = Product(name, newID, price, stock, createdAt);

    productRepository.registerProduct(newProduct);

    return newProduct;
};

std::optional<Product> ProductService::findProductByName(const std::string& name) {
    return productRepository.getProductByName(name);
};

std::optional<Product> ProductService::findProductByID(const int& id) {
    return productRepository.getProductByID(id);
};

std::vector<Product> ProductService::getAllProducts() {
    return productRepository.getAllProducts();
};

void ProductService::unregisterProduct(const std::string& name) {
    if (not productRepository.productExists(name)) {
        throw NotRegisteredProductException("Esse produto não foi encontrado no sistema");
    };
    
    productRepository.unregisterProduct(name);
};