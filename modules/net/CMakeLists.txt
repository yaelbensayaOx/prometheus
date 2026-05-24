add_library(prometheus_net src/socket.cpp src/http.cpp src/amqp.cpp)
target_include_directories(prometheus_net PUBLIC include)
target_link_libraries(prometheus_net PUBLIC OpenSSL::SSL Boost::system CURL::libcurl)
