#pragma once
#include "../common/libs.h"
// Manages files
class FileManager {
private:
	std::string path;

	void returnCursorToStart(std::ifstream& file);
	bool isFileOpen(std::ifstream& file);
	bool isFileEmpty(std::ifstream& file);
	bool isHeaderInts(std::ifstream& file);
	bool areIntsPositive(std::ifstream& file);
	bool areDimensionsCorrect(std::ifstream& file);
	bool areContentsAllowed(std::ifstream& file);
public:
	FileManager(const std::string& filePath);
	int runFileManager();
	bool loadGrid(std::vector<std::vector<int>>& grid);
};