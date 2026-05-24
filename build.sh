#!/usr/bin/env bash
set -euo pipefail

# Deps: openssl/1.1.1t, boost/1.79.0, zlib/1.2.11, fmt/9.1.0, spdlog/1.11.0
#       libpcap/1.10.1, nlohmann_json/3.11.2, rabbitmq-c/0.13.0, libcurl/7.85.0

BUILD_DIR="${BUILD_DIR:-build}"
mkdir -p "$BUILD_DIR"

echo "[prometheus] Configuring with Conan..."
if command -v conan &>/dev/null; then
    conan install . --output-folder="$BUILD_DIR" --build=missing
    cmake -B "$BUILD_DIR" -DCMAKE_TOOLCHAIN_FILE="$BUILD_DIR/conan_toolchain.cmake"
else
    echo "[prometheus] Conan not found — falling back to system libs"
    cmake -B "$BUILD_DIR"
fi

cmake --build "$BUILD_DIR" --parallel "$(nproc 2>/dev/null || sysctl -n hw.ncpu)"
echo "[prometheus] Build complete: $BUILD_DIR/prometheus"
