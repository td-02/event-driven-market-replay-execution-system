#pragma once
#include <cstdint>

class Event {
public:
    uint64_t timestamp_ns;

    explicit Event(uint64_t ts) : timestamp_ns(ts) {}

    virtual ~Event() = default;

    virtual void process() = 0;
};
