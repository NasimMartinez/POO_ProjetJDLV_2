#include "testTools.h"

bool TestTools::compare(const Grid& g, const std::vector<std::vector<int>>& expected) {
    if (g.getWidth() != expected.size() ||
        g.getHeight() != expected[0].size())
        return false;

    for (int x = 0; x < g.getWidth(); x++) {
        for (int y = 0; y < g.getHeight(); y++) {
            if (g.getCell(x, y).isAlive() != (expected[x][y] == 1))
                return false;
        }
    }
    return true;
}

bool TestTools::runTest(const std::vector<std::vector<int>>& start,
    const std::vector<std::vector<int>>& expected,
    int iterations,
    Rule& rules)
{
    int w = start.size();
    int h = start[0].size();

    Grid g(w, h);

    // Remplir la grille initiale
    for (int x = 0; x < w; x++)
        for (int y = 0; y < h; y++)
            g.setCell(x, y, start[x][y] == 1 ? (Cell*)new LivingCell : (Cell*)new DeadCell);

    // Jeu
    Game game(&g, &rules);

    for (int i = 0; i < iterations; i++)
        game.nextStep();

    // Comparaison
    return compare(g, expected);
}
