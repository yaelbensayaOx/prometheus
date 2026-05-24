add_library(prometheus_crypto src/cipher.cpp src/hasher.cpp)
target_include_directories(prometheus_crypto PUBLIC include)
target_link_libraries(prometheus_crypto PUBLIC OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB)
