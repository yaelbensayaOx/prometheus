#include "event_bus.h"
#include <amqp.h>
#include <amqp_tcp_socket.h>
#include <spdlog/spdlog.h>

EventBus::EventBus(const std::string& host, int port) : host_(host), port_(port) {
    conn_ = amqp_new_connection();
    amqp_socket_t* sock = amqp_tcp_socket_new(conn_);
    int status = amqp_socket_open(sock, host_.c_str(), port_);
    if (status != 0) {
        spdlog::error("Failed to connect to AMQP broker at {}:{}", host_, port_);
    }
}

EventBus::~EventBus() { amqp_destroy_connection(conn_); }

void EventBus::publish(const std::string& exchange, const std::string& key, const std::string& body) {
    amqp_basic_publish(conn_, 1,
        amqp_cstring_bytes(exchange.c_str()),
        amqp_cstring_bytes(key.c_str()),
        0, 0, nullptr,
        amqp_cstring_bytes(body.c_str()));
}
