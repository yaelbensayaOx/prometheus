#include "hasher.h"
#include <openssl/sha.h>
#include <zlib.h>
#include <sstream>
#include <iomanip>

std::string Hasher::sha256(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.c_str()), data.size(), hash);
    std::ostringstream oss;
    for (auto b : hash) oss << std::hex << std::setw(2) << std::setfill('0') << (int)b;
    return oss.str();
}

uint32_t Hasher::crc32_str(const std::string& data) {
    return ::crc32(0L, reinterpret_cast<const Bytef*>(data.c_str()), data.size());
}
