#pragma once

#include <stdexcept>
#include <string>

class InvalidProductException : public std::runtime_error {
    public:
        InvalidProductException(const std::string& message)
                : std::runtime_error(message) {}
        };