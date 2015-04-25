#pragma once
#include <vector>
#include "../pathfinding/obstruction-map.h"
class LevelManager
{
	std::vector<ObstructionMap> levels;
	void testLevel();
public:
	LevelManager();
	void loadLevels();
	ObstructionMap* getLevel(int num);
};

