#include "consoleMode.h"

void ConsoleMode::run(Game& game, const std::string& inputName) {
	int iteration;
	std::cout << "Nombre d'iterations ?" << std::endl;
	std::cin >> iteration;

	std::string outputDir = inputName + "_out";
}