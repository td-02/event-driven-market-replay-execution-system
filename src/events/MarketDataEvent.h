#pragma once
#include <iostream>
#include "Event.h"

class ReplayEngine;

class MarketDataEvent : public Event {
public:
    double price;
    double volume;
    ReplayEngine* engine;

    MarketDataEvent(uint64_t ts, double p, double v, ReplayEngine* eng)
        : Event(ts), price(p), volume(v), engine(eng) {}

    void process() override;
};
