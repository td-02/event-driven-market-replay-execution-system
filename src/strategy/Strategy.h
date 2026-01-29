#pragma once
#include "../events/MarketDataEvent.h"
#include "../execution/OrderIntent.h"

class Strategy {
public:
    virtual ~Strategy() = default;

    virtual void on_market_data(const MarketDataEvent& event) = 0;
};
