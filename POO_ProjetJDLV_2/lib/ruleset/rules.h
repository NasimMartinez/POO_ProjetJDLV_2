#pragma once
#include "../cells/cell.h"
#include "../common/libs.h"

// Abstract ruleset
class Rule {
public:
    virtual ~Rule() = default;
    virtual Cell* computeNextState(const Cell& current, int aliveNeighbors) const = 0;
};

// Custom rulesets
class ClassicConwayRule : public Rule {
public:
    Cell* computeNextState(const Cell& current, int aliveNeighbors) const override;
};

class BlinkRule : public Rule {
public:
    Cell* computeNextState(const Cell& current, int aliveNeighbors) const override;
};