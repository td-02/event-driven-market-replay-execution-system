#include "scheduler/EventScheduler.h"
#include "events/MarketDataEvent.h"
#include "replay/ReplayEngine.h"

int main() {
    EventScheduler scheduler;
    ReplayEngine replay_engine;

    scheduler.schedule(new MarketDataEvent(100, 101.5, 200, &replay_engine));
    scheduler.schedule(new MarketDataEvent(300, 102.1, 150, &replay_engine));
    scheduler.schedule(new MarketDataEvent(200, 101.8, 180, &replay_engine));

    while (!scheduler.empty()) {
        Event* e = scheduler.next();
        e->process();
        delete e;
    }

    return 0;
}
