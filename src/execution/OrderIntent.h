#pragma once
#include <cstdint>

enum class Side {
    BUY,
    SELL
};

struct OrderIntent {
    uint64_t timestamp_ns;
    Side side;
    double quantity;
};
