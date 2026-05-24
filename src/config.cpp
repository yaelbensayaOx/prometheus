#include "config.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

Config::Config(const std::string& path) {
    std::ifstream f(path);
    if (!f.is_open()) {
        spdlog::warn("Config file not found, using defaults");
        data_ = {{"workers", 4}, {"queue", "prometheus.tasks"}};
        return;
    }
    f >> data_;
}

int Config::workers() const { return data_.value("workers", 4); }
std::string Config::queue() const { return data_.value("queue", "prometheus.tasks"); }
