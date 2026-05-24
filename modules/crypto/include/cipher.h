#pragma once
#include <vector>
#include <cstdint>

class Cipher {
public:
    static std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plaintext, const std::vector<uint8_t>& key);
};
