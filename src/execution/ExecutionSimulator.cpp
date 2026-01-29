#include "ExecutionSimulator.h"

FillEvent ExecutionSimulator::execute(
    const OrderIntent& intent,
    double market_price
) {
    // Simple deterministic slippage model
    double slippage = 0.01; // 1 cent
    double impact = 0.0001 * intent.quantity;

    double executed_price = market_price + slippage + impact;

    FillEvent fill;
    fill.timestamp_ns = intent.timestamp_ns;
    fill.executed_price = executed_price;
    fill.quantity = intent.quantity;

    std::cout << "[EXECUTION] Filled qty=" << fill.quantity
              << " at price=" << fill.executed_price << std::endl;

    return fill;
}
