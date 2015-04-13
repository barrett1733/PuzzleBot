#include "SearchGrid.h"

SearchGrid::SearchGrid(int sizeX, int sizeY) :
	sizeX(sizeX),
	sizeY(sizeY)
{
	nodeGrid.alloc(sizeX, sizeY);
	boolGrid.alloc(sizeX, sizeY);
	clear();
}

SearchGrid::~SearchGrid() { }

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
