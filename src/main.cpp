#include "scheduler/EventScheduler.h"
#include "replay/ReplayEngine.h"
#include "data/CsvMarketDataLoader.h"

int main() {
    EventScheduler scheduler;
    ReplayEngine replay_engine;

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

    return 0;
}
