#pragma once
#include <vector>
#include "../utility/grid.h"
#include "../load/LoadFile.h"

class LevelManager : public LoadFile
{
	std::vector<GridBool> levels;
	Position parseCoords(std::string);
	int currentLevelLoading, currentLevel;
public:
	LevelManager();
	GridBool* getLevel(int num);
	void store(std::string, std::string);
};

