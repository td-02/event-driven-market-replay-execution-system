#pragma once
#include <vector>
#include "../events/MarketDataEvent.h"
#include "../events/ExecutionEvent.h"
#include "../strategy/Strategy.h"
#include "../execution/ExecutionSimulator.h"
#include "../metrics/MetricsCollector.h"
#include "../scheduler/EventScheduler.h"

class ReplayEngine {
private:
    std::vector<Strategy*> strategies;
    ExecutionSimulator executor;
    MetricsCollector metrics;

    EventScheduler* scheduler = nullptr;
    double last_price = 0.0;

    // Fixed deterministic latency (nanoseconds)
    const uint64_t execution_latency_ns = 50;

public:
    void attach_scheduler(EventScheduler* sched) {
        scheduler = sched;
    }

    void register_strategy(Strategy* strategy) {
        strategies.push_back(strategy);
    }

    void on_market_data(const MarketDataEvent& event) {
        last_price = event.price;
        metrics.on_market_price(event.price);

        for (Strategy* strat : strategies) {
            strat->on_market_data(event);
        }
    }

    // Called by strategy
    void on_order_intent(const OrderIntent& intent) {
        uint64_t exec_time = intent.timestamp_ns + execution_latency_ns;

        scheduler->schedule(
            new ExecutionEvent(exec_time, intent, this)
        );
    }

    // Called by ExecutionEvent
    void execute_with_latency(const OrderIntent& intent) {
        FillEvent fill = executor.execute(intent, last_price);
        metrics.on_fill(fill);
    }

    void report_metrics() const {
        metrics.report();
    }
};
