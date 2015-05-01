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

void LevelManager::loadLevels()
{
	testLevel();
}

void LevelManager::testLevel()
{
	int mapSizeX = 10;
	int mapSizeY = 10;

	levels.push_back(GridBool(10, 10));
	LEVELSIZE = 10;

	Position start = Position(0, 4);
	Position goal = Position(9, 4);

	std::vector<std::pair<int, int>> obs = {
			{ 2, 2 }, { 2, 3 }, { 2, 5 }, { 2, 6 },
			{ 3, 1 }, { 3, 2 }, { 3, 6 }, { 3, 7 },
			{ 4, 1 }, { 4, 7 },
			{ 5, 1 }, { 5, 2 }, { 5, 6 }, { 5, 7 },
			{ 6, 2 }, { 6, 3 }, { 6, 4 }, { 6, 5 }, { 6, 6 }
	};
	for (int i = 0; i < obs.size(); i++)
		levels[0].at(Position(obs[i].first, obs[i].second)) = true;
}

Position LevelManager::parseCoords(std::string coord)
{
	char delimiter = ',';
	int lineDelim = coord.find(delimiter);
	std::string x, y;

	x = coord.substr(0, lineDelim);
	y = coord.substr(lineDelim + 1, coord.size());

	return Position(atoi(x.c_str()), atoi(y.c_str()));

}

void LevelManager::store(std::string name, std::string data)
{
	if (name == "load")
	{
		currentLevelLoading++;
	}
	else if (name == "size")
	{
		LEVELSIZE = atoi(data.c_str());
		levels.push_back(GridBool(LEVELSIZE, LEVELSIZE));
		levels[currentLevelLoading].clear(false);
	}
	else if (name == "wall")
	{
		levels[currentLevelLoading].at(parseCoords(data)) = true;
	}
}