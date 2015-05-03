#pragma once

#include "pathfinding.h"
#include "../utility/entity.h"
#include "../utility/timer.h"
#include "PrintData.h"

static int mapSizeX = 10;
static int mapSizeY = 10;

enum SearchFlags
{
	SEARCH_NONE = 0,
	SEARCH_ALL = 1,
	SEARCH_ASTAR = 2,
	SEARCH_ASTARMOD = 4,
	SEARCH_HUMAN = 8,
	SEARCH_ASTAREXP = 16
};

void runAStarTest(Position start, Position goal, ObstructionMap* obsMap, int pf)
{
	cout << endl << "A* Test" << endl;

	Pathfinder test(mapSizeX, mapSizeY);

	Timer timer;
	timer.start();

	Path path = test.findPath(start, goal, obsMap);

	timer.stop();

	print(path, obsMap, timer, pf);
}

void runTests(Position start, Position goal, ObstructionMap* obsMap, int printflags, int searchFlag)
{
	if (searchFlag & SEARCH_ASTAR || searchFlag & SEARCH_ALL)
		runAStarTest(start, goal, obsMap, printflags);

	std::cout << std::endl << "Tests finished" << std::endl;
}
