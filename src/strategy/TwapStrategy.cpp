#include "TwapStrategy.h"
#include "../replay/ReplayEngine.h"

void TwapStrategy::on_market_data(const MarketDataEvent& event) {
    if (slices_sent >= total_slices) {
        return;
    }

    OrderIntent intent;
    intent.timestamp_ns = event.timestamp_ns;
    intent.side = Side::BUY;
    intent.quantity = total_quantity / total_slices;

    slices_sent++;

    std::cout << "[TWAP] Sending OrderIntent | time="
              << intent.timestamp_ns
              << " qty=" << intent.quantity << std::endl;

    engine->on_order_intent(intent);
}
