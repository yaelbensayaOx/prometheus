#pragma once
#include <string>
#include <amqp.h>

class EventBus {
public:
    EventBus(const std::string& host, int port);
    ~EventBus();
    void publish(const std::string& exchange, const std::string& key, const std::string& body);
private:
    std::string host_;
    int port_;
    amqp_connection_state_t conn_;
};
