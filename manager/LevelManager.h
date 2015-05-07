#pragma once
#include <vector>
#include "../utility/grid.h"
#include "../load/LoadFile.h"
#include "../load/AdditionalParsing.h"
#include "EntityManager.h"

class LevelManager : public LoadFile, public AdditionalParsing
{
	std::vector<GridBool> levels;
	GridBool obsMap;
	int currentLevelLoading, currentLevel;
public:
	LevelManager();
	EntityManager* entityManager;
	GridBool* getLevel(int num);
	GridBool* getObsMap();
	void store(std::string, std::string);
};

