#include "graphicMode.h"

static const int cellSize = 20;

static void renderGrid(sf::RenderWindow& window, const Grid& grid) {
    window.clear();

    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
    cell.setFillColor(sf::Color::White);

    for (int x = 0; x < grid.getWidth(); x++) {
        for (int y = 0; y < grid.getHeight(); y++) {
            if (grid.getCell(x, y).isAlive()) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }

    window.display();
}

void GraphicMode::run(Game& game) {
    const Grid& g = game.getGrid();

    sf::RenderWindow window(
        sf::VideoMode(g.getWidth() * cellSize, g.getHeight() * cellSize),
        "Game of Life"
    );

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window, game.getGrid());
        game.nextStep();

        sf::sleep(sf::milliseconds(120));
    }
}