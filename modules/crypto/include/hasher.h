#pragma once
#include <string>
#include <cstdint>

class Hasher {
public:
    static std::string sha256(const std::string& data);
    static uint32_t crc32_str(const std::string& data);
};
