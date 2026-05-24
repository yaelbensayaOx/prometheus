#include "pipeline.h"
#include <spdlog/spdlog.h>
#include <fmt/format.h>

Pipeline::Pipeline(const Config& cfg) : cfg_(cfg) {
    spdlog::info(fmt::format("Pipeline initialized, workers={}", cfg_.workers()));
}

void Pipeline::run() {
    spdlog::info("Pipeline running");
    // processing loop
}
