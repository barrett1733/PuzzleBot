#include "LevelManager.h"
#include "../config/Config.h"

LevelManager::LevelManager() : currentLevelLoading(-1), currentLevel(0)
{
	levels.reserve(10);
}

GridBool* LevelManager::getLevel(int num)
{
	if (num < levels.size())
	{
		return &levels.at(num);
	}
}

GridBool* LevelManager::getObsMap()
{
	for (int y = 0; y < Config::LEVELSIZE; y++)
		for (int x = 0; x < Config::LEVELSIZE; x++)
			obsMap.at(x, y) = levels[0].at(x, y);
	std::vector<Position> obsVec = entityManager->blockedPositions();
	for (int i = 0; i < obsVec.size(); i++)
	{
		obsVec[i].round();
		obsMap.at(obsVec[i]) = true;
	}
	return &obsMap;
}

void LevelManager::store(std::string name, std::string data)
{
	if (name == "load")
	{
		currentLevelLoading++;
	}
	else if (name == "size")
	{
		Config::LEVELSIZE = atoi(data.c_str());
		levels.push_back(GridBool(Config::LEVELSIZE, Config::LEVELSIZE));
		obsMap.alloc(Config::LEVELSIZE, Config::LEVELSIZE);
		levels[currentLevelLoading].clear(false);
	}
	else if (name == "wall")
	{
		levels[currentLevelLoading].at(parseCoords(data)) = true;
	}
}