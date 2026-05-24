#pragma once
#include <string>
#include <openssl/ssl.h>

class TlsSocket {
public:
    TlsSocket(const std::string& host, int port);
    ~TlsSocket();
private:
    std::string host_;
    int port_;
    SSL_CTX* ctx_;
};
