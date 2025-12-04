#include "testBlock.h"

#include "../grid/grid.h"
#include "../ruleset/rules.h"
#include "../cells/cell.h"
#include "../game/game.h"
#include <cassert>
#include <iostream>

void testBlockStable() {
    Grid* g = new Grid(4, 4);
    g.setCell(1, 1, new LivingCell());
    g.setCell(1, 2, new LivingCell());
    g.setCell(2, 1, new LivingCell());
    g.setCell(2, 2, new LivingCell());

    Rule* rule = new ClassicConwayRule();
    Game game(&g, rule);

    game.nextStep();
    const Grid& g1 = game.getGrid();

    assert(g1.getCell(1, 1).isAlive());
    assert(g1.getCell(1, 2).isAlive());
    assert(g1.getCell(2, 1).isAlive());
    assert(g1.getCell(2, 2).isAlive());

    game.nextStep();
    const Grid& g2 = game.getGrid();

    assert(g2.getCell(1, 1).isAlive());
    assert(g2.getCell(1, 2).isAlive());
    assert(g2.getCell(2, 1).isAlive());
    assert(g2.getCell(2, 2).isAlive());

    std::cout << "Test Block stable passé avec succès.\n";
}
