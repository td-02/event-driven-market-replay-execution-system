#include "MetricsCollector.h"
#include <iostream>

void MetricsCollector::on_market_price(double price) {
    if (!arrival_price_set) {
        arrival_price = price;
        arrival_price_set = true;
    }
}

void MetricsCollector::on_fill(const FillEvent& fill) {
    fills.push_back(fill);
}

void MetricsCollector::report() const {
    double total_qty = 0.0;
    double weighted_price = 0.0;

    for (const auto& fill : fills) {
        total_qty += fill.quantity;
        weighted_price += fill.executed_price * fill.quantity;
    }

    if (total_qty == 0.0) {
        std::cout << "[METRICS] No fills recorded" << std::endl;
        return;
    }

    double avg_exec_price = weighted_price / total_qty;
    double implementation_shortfall =
        (avg_exec_price - arrival_price) * total_qty;

    std::cout << "\n===== EXECUTION METRICS =====" << std::endl;
    std::cout << "Arrival Price: " << arrival_price << std::endl;
    std::cout << "Avg Exec Price: " << avg_exec_price << std::endl;
    std::cout << "Total Quantity: " << total_qty << std::endl;
    std::cout << "Implementation Shortfall: "
              << implementation_shortfall << std::endl;
    std::cout << "=============================\n";
}
