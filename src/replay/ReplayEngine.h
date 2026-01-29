#pragma once
#include <vector>
#include "../events/MarketDataEvent.h"
#include "../strategy/Strategy.h"
#include "../execution/ExecutionSimulator.h"

class ReplayEngine {
private:
    std::vector<Strategy*> strategies;
    ExecutionSimulator executor;
    double last_price = 0.0;

public:
    void register_strategy(Strategy* strategy) {
        strategies.push_back(strategy);
    }

    void on_market_data(const MarketDataEvent& event) {
        last_price = event.price;

        for (Strategy* strat : strategies) {
            strat->on_market_data(event);
        }
    }

    void on_order_intent(const OrderIntent& intent) {
        executor.execute(intent, last_price);
    }
};
