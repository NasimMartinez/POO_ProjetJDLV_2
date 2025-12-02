#include "rules.h"

Cell* ClassicConwayRule::computeNextState(const Cell& current, int livingNeighbors) const {
    if (current.isAlive()) {
        if (livingNeighbors == 2 || livingNeighbors == 3) {
            return new LivingCell();
        }
        return new DeadCell();
    }
    else {
        if (livingNeighbors == 3) {
            return new LivingCell();
        }

        return new DeadCell();
    }
}

Cell* BlinkRule::computeNextState(const Cell& current, int aliveNeighbors) const {
    if (current.isAlive()) {
        return new DeadCell();
    }
    return new LivingCell();
}