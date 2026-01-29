#include "TwapStrategy.h"

void TwapStrategy::on_market_data(const MarketDataEvent& event) {
    if (slices_sent >= total_slices) {
        return;
    }

    double slice_qty = total_quantity / total_slices;

    OrderIntent intent;
    intent.timestamp_ns = event.timestamp_ns;
    intent.side = Side::BUY;
    intent.quantity = slice_qty;

    slices_sent++;

    std::cout << "[TWAP] OrderIntent generated | time="
              << intent.timestamp_ns
              << " qty=" << intent.quantity << std::endl;
}
