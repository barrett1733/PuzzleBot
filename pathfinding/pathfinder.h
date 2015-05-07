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
		bool goalReached;
		NodeRef curNode;
		Position neighborPos;

		// A* Modified variables
		bool searchLimiter;
		NodeList searchList;
		int searchMax, searchCounter;
		NodeRef closestToGoalNode;

		// A* variables
		NodeList openList, closedList;

		double pathCost(Position a, Position b);
		double heursticCost(Position a, Position b);
		Path constructPath(Pathfinding::Node*, int sizex, int sizey);
		void clear();

	public:
		Pathfinder(int x, int y) :
			size_x(x), size_y(y),
			searchLimiter(false),
			indexGrid(x, y),
			searchMax((x * y))
		{};
		Pathfinder(int x, int y, bool limitSearch, int numOfNodesToSearch) :
			size_x(x), size_y(y),
			searchLimiter(limitSearch),
			indexGrid(x, y),
			searchMax(numOfNodesToSearch)
		{};
		void init(int x, int y);
		Path findPath(Position start, Position goal, GridBool* obstructionMap);
		Position findNextPosition(Position start, Position goal, GridBool* obstructionMap);
	};

}