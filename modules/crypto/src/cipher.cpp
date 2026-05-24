#include "cipher.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <vector>
#include <stdexcept>

std::vector<uint8_t> Cipher::encrypt(const std::vector<uint8_t>& plaintext, const std::vector<uint8_t>& key) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    std::vector<uint8_t> iv(16), out(plaintext.size() + 16);
    RAND_bytes(iv.data(), 16);
    int len = 0, total = 0;
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr, key.data(), iv.data());
    EVP_EncryptUpdate(ctx, out.data(), &len, plaintext.data(), plaintext.size());
    total += len;
    EVP_EncryptFinal_ex(ctx, out.data() + total, &len);
    total += len;
    out.resize(total);
    EVP_CIPHER_CTX_free(ctx);
    return out;
}
