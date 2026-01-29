#include "scheduler/EventScheduler.h"
#include "replay/ReplayEngine.h"
#include "data/CsvMarketDataLoader.h"
#include "strategy/TwapStrategy.h"

int main() {
    EventScheduler scheduler;
    ReplayEngine replay_engine;

    TwapStrategy twap(1000.0, 3, &replay_engine);
    replay_engine.register_strategy(&twap);

    CsvMarketDataLoader::load(
        "data/raw/market_data.csv",
        scheduler,
        replay_engine
    );

    while (!scheduler.empty()) {
        Event* e = scheduler.next();
        e->process();
        delete e;
    }

    replay_engine.report_metrics();

    return 0;
}
