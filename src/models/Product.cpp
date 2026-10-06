#include "models/Product.hpp"

int Product::getId() const {
    return this-> id;
};

long long Product::getCreatedAt() const {
    return this->createdAt;
};

Product::Product(std::string name, int id, double price, int stock, long long createdAt) {
    this->name = name;
    this->price = price;
    this->stock = stock;
    this->id = id;
    this->createdAt = createdAt;
};