#pragma once
#include <vector>
#include "../utility/grid.h"
#include "../load/LoadFile.h"

class LevelManager : public LoadFile
{
	std::vector<GridBool> levels;
	void testLevel();
	Position parseCoords(std::string);
	int currentLevelLoading, currentLevel;
public:
	LevelManager();
	void loadLevels();
	GridBool* getLevel(int num);
	void store(std::string, std::string);
};

