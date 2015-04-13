#pragma once
#include "node.h"
#include "../utility/grid.h"

class SearchGrid
{
	int sizeX, sizeY;
	Grid<Node> nodeGrid;
	Grid<bool> boolGrid;
public:
	SearchGrid(int sizeX, int sizeY);
	~SearchGrid();
	void clear();
	bool checkExists(Position);
	void add(Node);
	Node& get(Position);
};

