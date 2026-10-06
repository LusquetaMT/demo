#include "utils/StringUtils.hpp"

#include <string>
#include <vector>

std::string StringUtils::join(const std::vector<std::string>& values, const std::string& separator) {
    std::string result;

    for (int i = 0; i < values.size(); i++) {
        result += values[i];

        if (i < values.size() - 1) {
            result += separator;
        }
    }

    return result;
};