# High-Performance Market Replay & Execution Simulation Engine

A deterministic, event-driven system for replaying historical market data and simulating algorithmic trade execution under realistic latency, slippage, and market impact constraints.

This project focuses on **execution quality evaluation**, not price prediction, and mirrors the infrastructure used by professional buy-side quant and execution research teams.

---

## 🚀 Key Features

- Deterministic, event-driven market replay
- Time-ordered execution using a priority-based scheduler
- Pluggable execution strategies (TWAP, VWAP)
- Latency injection modeled as first-class events
- Realistic execution simulation (slippage + market impact)
- Buy-side execution metrics (implementation shortfall)
- Strategy benchmarking under identical market conditions

---

## 🧠 System Philosophy

Most quant projects focus on **signals**.

This system focuses on **how trades actually execute**.

Given the same market data and parameters, the engine always produces the same results — enabling reproducible, scientific evaluation of execution strategies.

---

## 🏗️ System Architecture

┌─────────────────────────┐
│ CSV Market Data │
│ (timestamp, price, vol)│
└───────────┬─────────────┘
│
▼
┌─────────────────────────┐
│ MarketDataEvent │
│ (Event Abstraction) │
└───────────┬─────────────┘
│
▼
┌─────────────────────────┐
│ Event Scheduler │
│ Priority Queue │
│ Deterministic Ordering │
└───────────┬─────────────┘
│
▼
┌─────────────────────────┐
│ Replay Engine │
│ - Routes events │
│ - Tracks prices │
└───────┬─────────┬───────┘
│ │
▼ ▼
┌────────────┐ ┌────────────┐
│ TWAP │ │ VWAP │
│ Strategy │ │ Strategy │
└────┬───────┘ └────┬───────┘
│ OrderIntent │
└──────────┬──────┘
▼
┌─────────────────────────┐
│ ExecutionEvent │
│ (Latency Injection) │
└───────────┬─────────────┘
▼
┌─────────────────────────┐
│ Execution Simulator │
│ - Slippage model │
│ - Market impact │
└───────────┬─────────────┘
▼
┌─────────────────────────┐
│ Fill Events │
└───────────┬─────────────┘
▼
┌─────────────────────────┐
│ Metrics Engine │
│ - Arrival price │
│ - Avg exec price │
│ - Impl. shortfall │
└─────────────────────────┘


---

## 📊 Implemented Strategies

### TWAP (Time-Weighted Average Price)
- Splits total order quantity evenly across time
- Simple and widely used benchmark execution strategy

### VWAP (Volume-Weighted Average Price)
- Trades proportionally to observed market volume
- Uses a participation-rate model
- Adapts execution aggressiveness to liquidity

Both strategies run on the **same replayed market data**, enabling fair comparison.

---

## ⏱️ Latency Modeling

Latency is modeled as a **first-class event**:

- Order intents schedule future execution events
- Execution occurs at `intent_time + latency`
- Scheduler guarantees correct temporal ordering
- Executions may occur between market data events

This preserves realism **without sacrificing determinism**.

---

## 📈 Execution Metrics

The engine computes buy-side execution quality metrics:

- Arrival Price
- Average Execution Price
- Total Executed Quantity
- Implementation Shortfall

Metrics are collected **per strategy**, allowing direct benchmarking (TWAP vs VWAP).

---

## 🔁 Determinism Guarantee

- Single-threaded, event-driven architecture
- Priority-queue–based scheduling
- No wall-clock dependencies
- Same input → same output

This enables reproducible experimentation and scientific evaluation.

---

## 🧪 Example Output

===== METRICS: TWAP =====
Arrival Price: 101.5
Avg Exec Price: 101.84
Implementation Shortfall: 343.33

===== METRICS: VWAP =====
Arrival Price: 101.5
Avg Exec Price: 101.76
Implementation Shortfall: 260.12


---

## 🛠️ Build & Run

### Compile (Windows / PowerShell)

```powershell
g++ -std=c++17 ^
src\main.cpp ^
src\events\MarketDataEvent.cpp ^
src\events\ExecutionEvent.cpp ^
src\data\CsvMarketDataLoader.cpp ^
src\strategy\TwapStrategy.cpp ^
src\strategy\VwapStrategy.cpp ^
src\execution\ExecutionSimulator.cpp ^
src\metrics\MetricsCollector.cpp ^
-Isrc ^
-o market_replay.exe
Run
.\market_replay.exe
