#pragma once
#include <cstdint>

struct FillEvent {
    uint64_t timestamp_ns;
    double executed_price;
    double quantity;
};
