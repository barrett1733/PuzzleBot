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
		Config::LEVELSIZE = atoi(data.c_str());
		levels.push_back(GridBool(Config::LEVELSIZE, Config::LEVELSIZE));
		levels[currentLevelLoading].clear(false);
	}
	else if (name == "wall")
	{
		levels[currentLevelLoading].at(parseCoords(data)) = true;
	}
}