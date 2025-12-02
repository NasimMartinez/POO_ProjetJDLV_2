#include "manager.h"

void Manager::run() {
    std::string path;
    std::cout << "Fournir le chemin d'acces: ";
    std::cin >> path;

    FileManager fm(path);
    if (fm.runFileManager() != 0) {
        return;
    }

    std::vector<std::vector<int>> rawGrid;
    fm.loadGrid(rawGrid);

    // ---- Convert ints into Grid of Cell* ----
    int nbLines = rawGrid.size();
    int nbColumns = rawGrid[0].size();

    Grid* grid = new Grid(nbColumns, nbLines);

    for (int x = 0; x < nbColumns; ++x) {
        for (int y = 0; y < nbLines; ++y) {
            if (rawGrid[y][x] == 1)
                grid->setCell(x, y, new LivingCell());
            else
                grid->setCell(x, y, new DeadCell());
        }
    }

    // ---- Create Game ----
    Rule* rule = new ClassicConwayRule();
    Game game(grid, rule);

    std::cout << "Quel mode souhaitez vous utiliser ?" << std::endl;
    std::cout << "1. Mode console" << std::endl;
    std::cout << "2. Mode graphique" << std::endl;

    int mode;
    std::cin >> mode;
    if (mode == 1) runConsole(game, path);
    else if (mode == 2) runGraphical(game);
    else std::cout << "Pas un mode valide !";
    return;
}

void Manager::runConsole(Game& game, const std::string& inputName) {
    ConsoleMode c;
    c.run(game, inputName);
}

void Manager::runGraphical(Game& game) {
    GraphicMode g;
    g.run(game);
}