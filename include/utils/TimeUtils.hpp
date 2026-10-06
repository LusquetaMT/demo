#pragma once

#include <string>

class TimeUtils {
    public:
        static long long generateTimestamp();
        static std::string formatTimestamp(long long time);
};