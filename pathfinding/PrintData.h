#pragma once

#include "Obstruction-Map.h"
#include "pathfinding.h"
#include "../utility/timer.h"

enum PrintFlags
{
	PRINT_NONE = 0x0,
	PRINT_ALL = 0x1,
	PRINT_GRID = 0x2,
	PRINT_COORDS = 0x4,
	PRINT_TOTAL_TIME = 0x8,
	PRINT_AVERAGE_TIME = 0x10
};

void printPathAsGrid(Path& poslist, ObstructionMap* obsMap)
{
	ObstructionMap grid(*obsMap);

	for (int i = 0; i < poslist.size(); i++)
	{
		grid.at(poslist[i]) = OT_CONSIDERED;
	}
	std::cout << grid << std::endl;
}

void printPathAsCoordinates(Path& poslist)
{
	for (int i = 0; i < poslist.size(); i++)
	{
		std::cout << poslist[i] << ", ";
	}
	std::cout << std::endl;
}

static void print(Path& path, ObstructionMap *obsMap, Timer& timer, int pf)
{
	if (pf & PRINT_COORDS || pf & PRINT_ALL)
		printPathAsCoordinates(path);
	if (pf & PRINT_GRID || pf & PRINT_ALL)
		printPathAsGrid(path, obsMap);
	if (pf & PRINT_TOTAL_TIME || pf & PRINT_ALL)
		timer.printTotal();
	if (pf & PRINT_AVERAGE_TIME || pf & PRINT_ALL)
		timer.printAverage();
}

