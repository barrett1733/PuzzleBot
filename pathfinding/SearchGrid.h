#pragma once
#include "node.h"
#include "../utility/grid.h"

namespace Pathfinding
{
	class SearchGrid
	{
		int sizeX, sizeY;
		Grid<Node> nodeGrid;
		Grid<bool> boolGrid;
	public:
		SearchGrid(int sizeX, int sizeY);
		~SearchGrid();
		void init(int x, int y);
		void clear();
		bool checkExists(Position);
		void add(Node);
		Node& get(Position);
	};
}