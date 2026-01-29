#pragma once
#include <vector>
#include "../execution/FillEvent.h"

class MetricsCollector {
private:
    std::vector<FillEvent> fills;
    double arrival_price = 0.0;
    bool arrival_price_set = false;

public:
    void on_market_price(double price);
    void on_fill(const FillEvent& fill);
    void report() const;
};
