#pragma once

#include <string>
#include <vector>

class StringUtils {
    public:
        static std::string join(const std::vector<std::string>& values, const std::string& separator);
};