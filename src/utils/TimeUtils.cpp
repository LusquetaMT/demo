#include "utils/TimeUtils.hpp"

#include <ctime>
#include <iomanip>
#include <sstream>
#include <chrono>

long long TimeUtils::generateTimestamp() {
    auto now = std::chrono::system_clock::now();

    long long createdAt =
        std::chrono::duration_cast<std::chrono::seconds>(
            now.time_since_epoch()
        ).count();

    return createdAt;
};

std::string TimeUtils::formatTimestamp(long long timestamp) {
    std::time_t time = static_cast<std::time_t>(timestamp);

    std::tm localTime{};

    localtime_s(&localTime, &time);

    std::ostringstream output;

    output << std::put_time(&localTime, "%d/%m/%Y - %H:%M:%S");

    return output.str();
}