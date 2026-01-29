#pragma once
#include "Event.h"
#include "../execution/OrderIntent.h"

class ReplayEngine;

class ExecutionEvent : public Event {
private:
    OrderIntent intent;
    ReplayEngine* engine;

public:
    ExecutionEvent(
        uint64_t ts,
        const OrderIntent& intent_,
        ReplayEngine* eng
    ) : Event(ts), intent(intent_), engine(eng) {}

    void process() override;
};
