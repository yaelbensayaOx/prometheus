from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class PrometheusConan(ConanFile):
    name = "prometheus"
    version = "2.1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("openssl/1.1.1t")
        self.requires("boost/1.79.0")
        self.requires("zlib/1.2.11")
        self.requires("fmt/9.1.0")
        self.requires("spdlog/1.11.0")
        self.requires("libpcap/1.10.1")
        self.requires("nlohmann_json/3.11.2")
        self.requires("rabbitmq-c/0.13.0")
        self.requires("libcurl/7.85.0")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
