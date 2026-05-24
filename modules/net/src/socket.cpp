#include "socket.h"
#include <openssl/ssl.h>
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>

TlsSocket::TlsSocket(const std::string& host, int port) : host_(host), port_(port) {
    SSL_library_init();
    ctx_ = SSL_CTX_new(TLS_client_method());
}

TlsSocket::~TlsSocket() { SSL_CTX_free(ctx_); }
