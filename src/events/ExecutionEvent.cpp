#include "ExecutionEvent.h"
#include "../replay/ReplayEngine.h"
#include <iostream>

void ExecutionEvent::process() {
    std::cout << "[EXECUTION EVENT] scheduled_time="
              << timestamp_ns << std::endl;

    engine->execute_with_latency(intent);
}
