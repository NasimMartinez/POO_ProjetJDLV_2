#pragma once
#include "../grid/grid.h"
#include "../ruleset/rules.h"

// Computes game iterations
class Game {
private:
    Grid* grid;
    Rule* rule;

public:
    Game(Grid* grid, Rule* rule) : grid(grid), rule(rule) {};
    ~Game() {
        delete grid;
        delete rule;
    };

    void nextStep() { grid->update(*rule); };
    const Grid& getGrid() const { return *grid; };
};