#include "CsvMarketDataLoader.h"
#include "../events/MarketDataEvent.h"

#include <fstream>
#include <sstream>
#include <iostream>

void CsvMarketDataLoader::load(
    const std::string& file_path,
    EventScheduler& scheduler,
    ReplayEngine& replay_engine
) {
    std::ifstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << file_path << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        uint64_t timestamp;
        double price;
        double volume;

        std::getline(ss, token, ',');
        timestamp = std::stoull(token);

        std::getline(ss, token, ',');
        price = std::stod(token);

        std::getline(ss, token, ',');
        volume = std::stod(token);

        scheduler.schedule(
            new MarketDataEvent(timestamp, price, volume, &replay_engine)
        );
    }

    file.close();
}
