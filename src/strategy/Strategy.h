#pragma once
#include "../events/MarketDataEvent.h"
#include "../execution/OrderIntent.h"

class ReplayEngine;

class Strategy {
protected:
    ReplayEngine* engine;

public:
    explicit Strategy(ReplayEngine* eng) : engine(eng) {}
    virtual ~Strategy() = default;

    virtual void on_market_data(const MarketDataEvent& event) = 0;
};
