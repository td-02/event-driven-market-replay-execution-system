#include <iostream>
#include "scheduler/EventScheduler.h"
#include "events/TestEvent.h"

int main() {
    EventScheduler scheduler;

    scheduler.schedule(new TestEvent(300, 3));
    scheduler.schedule(new TestEvent(100, 1));
    scheduler.schedule(new TestEvent(200, 2));

    while (!scheduler.empty()) {
        Event* event = scheduler.next();
        event->process();
        delete event;
    }

    return 0;
}
