#include "MarketDataEvent.h"
#include "../replay/ReplayEngine.h"

void MarketDataEvent::process() {
    std::cout << "[MarketData] time=" << timestamp_ns
              << " price=" << price
              << " volume=" << volume << std::endl;

    engine->on_market_data(*this);
}
