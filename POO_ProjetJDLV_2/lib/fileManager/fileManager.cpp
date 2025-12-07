#include "fileManager.h"

FileManager::FileManager(const std::string& filePath) : path(filePath) {}

int FileManager::runFileManager() {
	std::ifstream file(path);

	if (!isFileOpen(file)) {
		std::cerr << "Erreur : Impossible d'ouvrir le fichier!" << std::endl;
		return 1;
	}
	if (!isFileEmpty(file)) {
		std::cerr << "Erreur : Fichier est vide!" << std::endl;
		return 1;
	}
	if (!isHeaderInts(file)) {
		std::cerr << "Erreur : La premiere ligne doit contenir 2 entiers!" << std::endl;
		return 1;
	}
	if (!areIntsPositive(file)) {
		std::cerr << "Erreur : Les entiers dans la premiere ligne doivent etre positifs!" << std::endl;
		return 1;
	}
	if (!areDimensionsCorrect(file)) {
		std::cerr << "Erreur : La matrice n'a pas les dimensions specifiees a la premiere ligne!" << std::endl;
		return 1;
	}
	if (!areContentsAllowed(file)) {
		std::cerr << "Erreur : La matrice peut seulement contenir des 1 ou 0!" << std::endl;
		return 1;
	}
	// Passes all checks
	return 0;
}

bool FileManager::loadGrid(std::vector<std::vector<int>>& grid) {
	std::ifstream file(path);
	if (!file.is_open()) {
		return false;
	}
	returnCursorToStart(file);

	int nbLines, nbColumns;
	file >> nbLines >> nbColumns;

	grid.assign(nbLines, std::vector<int>(nbColumns));

	for (int i = 0; i < nbLines; i++) {
		for (int j = 0; j < nbColumns; j++) {
			file >> grid[i][j];
		}
	}
	return true;
}

/**********Dependencies for runFileManager method***********/

void FileManager::returnCursorToStart(std::ifstream& file) {
	file.clear();
	file.seekg(std::ios_base::beg);
	return;
}

bool FileManager::isFileOpen(std::ifstream& file) {
	return file.is_open();
}

bool FileManager::isFileEmpty(std::ifstream& file) {
	returnCursorToStart(file);
	std::string line;
	if (!std::getline(file, line)) {
		return false;
	}
	return true;
}

bool FileManager::isHeaderInts(std::ifstream& file) {
	returnCursorToStart(file);
	std::string line;
	std::getline(file, line);

	std::istringstream issHeader(line);
	int nbLines, nbColumns;

	if (!(issHeader >> nbLines >> nbColumns)) {
		return false;
	}

	std::string leftover;
	if (issHeader >> leftover) {
		return false;
	}
	return true;
}

bool FileManager::areIntsPositive(std::ifstream& file) {
	returnCursorToStart(file);
	std::string line;
	std::getline(file, line);

	std::istringstream issHeader(line);
	int nbLines, nbColumns;

	issHeader >> nbLines >> nbColumns;
	return (nbLines > 0 && nbColumns > 0);
}

bool FileManager::areDimensionsCorrect(std::ifstream& file) {
	returnCursorToStart(file);
	std::string line;
	std::getline(file, line);

	std::istringstream issHeader(line);
	int nbLines, nbColumns;

	issHeader >> nbLines >> nbColumns;
	int cLine = 0, cColumn = 0;
	char c;
	while (file.get(c)) {
		if (c == ' ') {
			if (++cColumn >= nbColumns) {
				return false;
			}
		} if (c == '\n') {
			if (++cColumn != nbColumns) {
				return false;
			}
			// Saut de ligne
			cColumn = 0;

			if (++cLine >= nbLines) {
				return false;
			}
		}
	}
	if (++cLine < nbLines) {
		return false;
	}

	return true;
}

bool FileManager::areContentsAllowed(std::ifstream& file) {
	returnCursorToStart(file);
	std::string line;
	std::getline(file, line);

	char c;
	while (file.get(c)) {
		if (c != '1' && c != '0' && c != ' ' && c != '\n') {
			return false;
		}
	}
	return true;
}