#pragma once

#include <stdexcept>
#include <string>

class DuplicatedProductException : public std::runtime_error {
    public:
        DuplicatedProductException(const std::string& message)
                : std::runtime_error(message) {}
        };