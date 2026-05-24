cmake_minimum_required(VERSION 3.18)
project(prometheus VERSION 2.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem program_options)
find_package(ZLIB REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(CURL REQUIRED)

add_subdirectory(modules/crypto)
add_subdirectory(modules/net)

add_executable(prometheus
    src/main.cpp
    src/pipeline.cpp
    src/config.cpp
    src/event_bus.cpp
)

target_include_directories(prometheus PRIVATE include)
target_link_libraries(prometheus
    PRIVATE
    prometheus_crypto
    prometheus_net
    OpenSSL::SSL OpenSSL::Crypto
    Boost::system Boost::filesystem Boost::program_options
    ZLIB::ZLIB
    fmt::fmt
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    CURL::libcurl
)
