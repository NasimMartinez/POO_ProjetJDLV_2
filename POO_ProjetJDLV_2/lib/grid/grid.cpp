#include "grid.h"

Grid::Grid(int width, int height) {
	this->width = width;
	this->height = height;
	cells.resize(width, std::vector<Cell*>(height, nullptr));

	// Initializes all cells as deadCells by default
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			cells[x][y] = new DeadCell();
		}
	}
}

Grid::~Grid() {
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			delete cells[x][y];
		}
	}
}

void Grid::setCell(int x, int y, Cell* cell) {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		std::cerr << "Erreur : Out of range" << std::endl;
		return;
	}

	delete cells[x][y];
	cells[x][y] = cell;
}

const Cell& Grid::getCell(int x, int y) const {
	if (x < 0 || x >= width || y < 0 || y >= height) {
		throw std::out_of_range("Grid::getCell : coordinates out of range");
	}

	return *cells[x][y];
}

int Grid::countAliveNeighbors(int x, int y) const {
	int count = 0;

	for (int X = -1; X <= 1; ++X) {
		for (int Y = -1; Y <= 1; ++Y) {
			// Se saute soi même
			if (X == 0 && Y == 0) continue;

			int XCell = X + x;
			int YCell = Y + y;

			// Saute les cellules hors de la grille
			if (XCell < 0 || XCell >= width || YCell < 0 || YCell >= height) continue;

			if (cells[XCell][YCell]->isAlive()) {
				count++;
			}
		}
	}

	return count;
}

void Grid::update(const Rule& rule) {
	// Creation d'une nouvelle grille pour la nouvelle iteration
	std::vector<std::vector<Cell*>> nextGen(
		width, std::vector<Cell*>(height, nullptr)
	);

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {

			int aliveNeighbors = countAliveNeighbors(x, y);

			// Calcule le prochain etat de la cellule utilisant les regles fournies
			Cell* nextState = rule.computeNextState(*cells[x][y], aliveNeighbors);

			// Stocke un clone de la cellule
			nextGen[x][y] = nextState->clone();
			delete nextState;
		}
	}

	// On efface la grille precedente
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			delete cells[x][y];
		}
	}

	// On remplace avec la nouvelle grille
	cells = std::move(nextGen);
}

int Grid::getWidth() const {
	return width;
}

int Grid::getHeight() const {
	return height;
}