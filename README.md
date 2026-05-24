# prometheus

Distributed event-processing platform. Hybrid build: Conan (preferred) or
system libs via Makefile/build.sh.

Build methods:
  ./build.sh                # auto-detects Conan; falls back to system libs
  cmake -B build && cmake --build build
  make

Dependencies: openssl/1.1.1t, boost/1.79.0, zlib/1.2.11, fmt/9.1.0,
  spdlog/1.11.0, libpcap/1.10.1, nlohmann_json/3.11.2, rabbitmq-c/0.13.0,
  libcurl/7.85.0
