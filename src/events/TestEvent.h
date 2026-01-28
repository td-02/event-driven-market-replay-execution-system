#pragma once
#include <iostream>
#include "Event.h"

class TestEvent : public Event {
private:
    int id;

public:
    TestEvent(uint64_t ts, int id_)
        : Event(ts), id(id_) {}

    void process() override {
        std::cout << "Processing Event ID=" << id
                  << " at time=" << timestamp_ns << std::endl;
    }
};
