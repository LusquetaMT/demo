#pragma once

#include <string>

class Product {
    public:
        std::string name;
        double price;
        int stock;
        
        int getId() const;
        long long getCreatedAt() const;
        
        Product(std::string name, int id, double price, int stock, long long createdAt);

    private:
        long long createdAt;
        int id;
};