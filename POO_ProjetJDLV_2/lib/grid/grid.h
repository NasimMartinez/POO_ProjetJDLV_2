#pragma once
#include "../cells/cell.h"
#include "../ruleset/rules.h"
#include "../common/libs.h"

// Contains cells
class Grid {
private:
    std::vector<std::vector<Cell*>> cells;
    int width;
    int height;

public:
    Grid(int width, int height);
    ~Grid();

    void setCell(int x, int y, Cell* cell);
    const Cell& getCell(int x, int y) const;

    int countAliveNeighbors(int x, int y) const;
    void update(const Rule& rule);

    int getWidth() const;
    int getHeight() const;
};