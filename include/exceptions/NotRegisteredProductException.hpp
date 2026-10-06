#pragma once

#include <stdexcept>
#include <string>

class NotRegisteredProductException : public std::runtime_error {
    public:
        NotRegisteredProductException(const std::string& message)
                : std::runtime_error(message) {}
        };