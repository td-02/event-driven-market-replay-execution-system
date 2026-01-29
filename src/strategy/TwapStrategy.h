#pragma once
#include "Strategy.h"
#include <iostream>

class TwapStrategy : public Strategy {
private:
    double total_quantity;
    int total_slices;
    int slices_sent;

public:
    TwapStrategy(double qty, int slices)
        : total_quantity(qty),
          total_slices(slices),
          slices_sent(0) {}

    void on_market_data(const MarketDataEvent& event) override;
};
