#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include "obstruction-map.h"
#include "nodelist.h"
#include "SearchGrid.h"
#include "../utility/distance.h"

typedef std::vector<Position> Path;
typedef std::vector<Pathfinding::Node> NodeVector;
namespace Pathfinding
{
	class Pathfinder
	{
		typedef Pathfinding::Node* NodeRef;
		int size_x, size_y;

		SearchGrid indexGrid;
		NodeList searchList;
		bool goalReached;
		NodeRef curNode, closestToGoalNode;
		Position neighborPos;

		double pathCost(Position a, Position b);
		double heursticCost(Position a, Position b);
		Path constructPath(Pathfinding::Node*, int sizex, int sizey);
		void clear();

	public:
		Pathfinder(int x, int y) :
			size_x(x), size_y(y),
			indexGrid(x, y)
		{};
		void init(int x, int y);
		Path findPath(Position start, Position goal, GridBool* obstructionMap);
		Position findNextPosition(Position start, Position goal, GridBool* obstructionMap);
	};

}