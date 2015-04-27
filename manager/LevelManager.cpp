#include "LevelManager.h"
#include "../pathfinding\obstruction-map.h"

LevelManager::LevelManager()
{
	levels.reserve(10);
}

ObstructionMap* LevelManager::getLevel(int num)
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

	levels.push_back(ObstructionMap(10, 10));

	Position::max_x = mapSizeX;
	Position::max_y = mapSizeY;

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
		levels[0].at(Position(obs[i].first, obs[i].second)) = OT_OBSTRUCTED;
}