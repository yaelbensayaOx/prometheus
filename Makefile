CXX      := g++
CXXFLAGS := -std=c++17 -Iinclude -Imodules/crypto/include -Imodules/net/include \
            -I/usr/local/include
LDFLAGS  := -L/usr/local/lib \
            -lssl -lcrypto -lz -lcurl -lpcap -lrabbitmq \
            -lboost_system -lboost_filesystem -lfmt -lspdlog

# Pinned system deps (fallback when Conan unavailable):
#   openssl 1.1.1t  |  boost 1.79.0  |  zlib 1.2.11
#   libcurl 7.85.0  |  libpcap 1.10.1  |  rabbitmq-c 0.13.0

SRCS := src/main.cpp src/pipeline.cpp src/config.cpp src/event_bus.cpp \
        modules/crypto/src/cipher.cpp modules/crypto/src/hasher.cpp \
        modules/net/src/socket.cpp modules/net/src/http.cpp modules/net/src/amqp.cpp
OBJS := $(SRCS:.cpp=.o)

all: prometheus

prometheus: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -delete && rm -f prometheus
