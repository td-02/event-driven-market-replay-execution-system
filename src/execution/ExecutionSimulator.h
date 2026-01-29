#pragma once
#include <iostream>
#include "OrderIntent.h"
#include "FillEvent.h"

class ExecutionSimulator {
public:
    FillEvent execute(
        const OrderIntent& intent,
        double market_price
    );
};
