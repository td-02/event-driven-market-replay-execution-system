#pragma once
#include <string>
#include "../scheduler/EventScheduler.h"
#include "../replay/ReplayEngine.h"

class CsvMarketDataLoader {
public:
    static void load(
        const std::string& file_path,
        EventScheduler& scheduler,
        ReplayEngine& replay_engine
    );
};
