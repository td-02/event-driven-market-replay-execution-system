#pragma once
#include <vector>
#include "../events/MarketDataEvent.h"
#include "../strategy/Strategy.h"

class ReplayEngine {
private:
    std::vector<Strategy*> strategies;

public:
    void register_strategy(Strategy* strategy) {
        strategies.push_back(strategy);
    }

    void on_market_data(const MarketDataEvent& event) {
        for (Strategy* strat : strategies) {
            strat->on_market_data(event);
        }
    }
};
