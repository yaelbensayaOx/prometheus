#include <iostream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <boost/program_options.hpp>
#include "pipeline.h"
#include "config.h"

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    po::options_description desc("prometheus options");
    desc.add_options()
        ("help,h", "show help")
        ("config,c", po::value<std::string>()->default_value("config.json"), "config file");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) { std::cout << desc << "\n"; return 0; }

    spdlog::set_level(spdlog::level::info);
    spdlog::info("prometheus v2.1.0 starting");

    Config cfg(vm["config"].as<std::string>());
    Pipeline pipeline(cfg);
    pipeline.run();
    return 0;
}
