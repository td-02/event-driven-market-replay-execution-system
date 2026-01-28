#pragma once
#include "../events/Event.h"

struct EventComparator {
    bool operator()(const Event* a, const Event* b) const {
        return a->timestamp_ns > b->timestamp_ns;
    }
};
