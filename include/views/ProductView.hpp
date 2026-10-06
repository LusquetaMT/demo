#pragma once

#include "models/Product.hpp"
#include <string>
#include <vector>

class ProductView {
    public:
        int askConfirm();
        bool askRepeat(const std::string& msg);
        std::string askName();
        int askInitialStock();
        double askPrice();
        int askID();
        
        void showRegisterMenu() const;
        void showListMenu() const;
        void showProduct(const Product& product) const;
        void showError(const std::string& msg) const;
        void showWarn(const std::string& msg) const;
        void showProductNames(const std::vector<std::string>& names) const;
};