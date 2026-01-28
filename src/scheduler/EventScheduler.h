#pragma once
#include <queue>
#include "../events/Event.h"
#include "EventComparator.h"

class EventScheduler {
private:
    std::priority_queue<Event*, std::vector<Event*>, EventComparator> queue;

public:
    void schedule(Event* event) {
        queue.push(event);
    }

    bool empty() const {
        return queue.empty();
    }

    Event* next() {
        Event* e = queue.top();
        queue.pop();
        return e;
    }
};
