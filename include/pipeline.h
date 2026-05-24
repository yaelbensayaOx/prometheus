#pragma once
#include "config.h"

class Pipeline {
public:
    explicit Pipeline(const Config& cfg);
    void run();
private:
    const Config& cfg_;
};
