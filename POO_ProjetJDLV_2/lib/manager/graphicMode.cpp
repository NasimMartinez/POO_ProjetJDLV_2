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
    int timeBetweenIterations = 120;
    bool isPaused = false;

    while (window.isOpen()) {
        sf::Event e;

        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();

            else if (e.type == sf::Event::KeyPressed) {
                std::cout << "key pressed !" << std::endl;
                switch (e.key.code) {
                case sf::Keyboard::P:
                    if (timeBetweenIterations > 0) timeBetweenIterations = timeBetweenIterations - 10;
                    break;
                case sf::Keyboard::M:
                    if (timeBetweenIterations < 500) timeBetweenIterations = timeBetweenIterations + 10;
                    break;
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Space:
                    isPaused = !isPaused;
                }
                
            }
        }
        renderGrid(window, game.getGrid());
        if (!isPaused) {
            std::cout << timeBetweenIterations << std::endl;
            game.nextStep();
        }

        sf::sleep(sf::milliseconds(timeBetweenIterations));
    }
}