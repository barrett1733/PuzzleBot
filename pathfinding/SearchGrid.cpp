#include "SearchGrid.h"
using namespace Pathfinding;

SearchGrid::SearchGrid(int sizeX, int sizeY)
{
	init(sizeX, sizeY);
}

SearchGrid::~SearchGrid() { }

void SearchGrid::init(int x, int y)
{
	sizeX = x;
	sizeY = y;
	nodeGrid.alloc(sizeX, sizeY);
	boolGrid.alloc(sizeX, sizeY);
	clear();
}

void SearchGrid::clear()
{
	for (int x = 0; x < sizeX; x++)
		for (int y = 0; y < sizeY; y++)
			boolGrid.at(x, y) = false;
}

bool SearchGrid::checkExists(Position pos)
{
	return boolGrid.at(pos);
}

void SearchGrid::add(Node node)
{
	nodeGrid.at(node.pos) = node;
	boolGrid.at(node.pos) = true;
}

Node& SearchGrid::get(Position pos)
{
	return nodeGrid.at(pos);
}
