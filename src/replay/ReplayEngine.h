#pragma once
#include "../events/MarketDataEvent.h"

class ReplayEngine {
public:
    void on_market_data(const MarketDataEvent& event) {
        // For now, just print.
        // Later: forward to strategy, execution engine, etc.
        std::cout << "[ReplayEngine] received market data" << std::endl;
    }
};
