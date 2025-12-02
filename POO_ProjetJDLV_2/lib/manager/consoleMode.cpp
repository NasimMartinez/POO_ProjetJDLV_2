#include "consoleMode.h"
void ConsoleMode::run(Game& game, const std::string& inputName) {
	int iteration;
	std::cout << "Nombre d'iterations ?" << std::endl;
	std::cin >> iteration;

	std::string outputDir = inputName + "_out";
	std::filesystem::create_directory(outputDir);

    for (int i = 0; i < iteration; i++) {
        std::string filename = outputDir + "/iteration_" + std::to_string(i) + ".txt";
        std::ofstream out(filename);

        const Grid& g = game.getGrid();
        out << g.getHeight() << " " << g.getWidth() << "\n";

        for (int y = 0; y < g.getHeight(); y++) {
            for (int x = 0; x < g.getWidth(); x++) {
                out << (g.getCell(x, y).isAlive() ? 1 : 0) << " ";
            }
            out << "\n";
        }

        game.nextStep();
    }

    std::cout << "Fin mode console" << std::endl;

}