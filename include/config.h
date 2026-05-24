#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Config {
public:
    explicit Config(const std::string& path);
    int workers() const;
    std::string queue() const;
private:
    nlohmann::json data_;
};
