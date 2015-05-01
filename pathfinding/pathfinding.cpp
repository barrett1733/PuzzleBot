#include "pathfinding.h"
#include "../config/Config.h"

double Pathfinding::heursticCost(Position a, Position b)
{
	return ManhattanDistance(a, b);
}

double Pathfinding::pathCost(Position a, Position b)
{
	return EuclideanDistance(a, b);
}

Path Pathfinding::findPath(Position start, Position goal, GridBool* obstructionMap)
{
	goalReached = false;
	searchCounter = 0;

	indexGrid.add(Node(start, NULL, 0, heursticCost(neighborPos, goal)));

	searchList.push(&indexGrid.get(start));

	closestToGoalNode = &indexGrid.get(start);
	curNode = NULL;

	while (!goalReached && (!searchLimiter || searchCounter <= searchMax))
	{
		searchCounter++;

		if (searchList.empty())
			return constructPath(closestToGoalNode);

		curNode = searchList.pop();

		// this is questionable
		if (curNode->fcost < closestToGoalNode->fcost)
			closestToGoalNode = curNode;

		if (curNode->pos == goal)
		{
			goalReached = true;
		}
		else
		{
			for (Direction dir = D_NORTH; dir < D_NORTH_EAST; dir++)
			{
				neighborPos = curNode->pos;
				neighborPos.move(dir);
				if (neighborPos.checkSanity(LEVELSIZE, LEVELSIZE) && obstructionMap->at(neighborPos) == false)
				{
					if (indexGrid.checkExists(neighborPos))
					{
						if (curNode->gcost < indexGrid.get(neighborPos).gcost)
						{
							indexGrid.add(Node(neighborPos, curNode, curNode->gcost, heursticCost(neighborPos, goal)));
						}
					}
					else
					{
						double travelCost = pathCost(curNode->pos, neighborPos);
						double newgcost = curNode->gcost + travelCost;
						double hcost = heursticCost(neighborPos, goal);

						indexGrid.add(Node(neighborPos, curNode, newgcost, hcost));
						searchList.push(&indexGrid.get(neighborPos));
					}
				}
			}
		}
	}
	return constructPath(curNode);
}

// Does not include original position
Path Pathfinding::constructPath(Node* goal)
{
	Node* node = goal;
	Path path;
	path.reserve(LEVELSIZE * LEVELSIZE);

	if (node->parentNode == NULL)
	{
		path.push_back(node->pos);
		return path;
	}

	while (node->parentNode != NULL)
	{
		path.push_back(node->pos);
		node = node->parentNode;
	}
	std::reverse(path.begin(), path.end());

	clear();
	return path;
}

void Pathfinding::clear()
{
	searchList.clear();
	indexGrid.clear();
}

Position Pathfinding::findNextPosition(Position start, Position goal, GridBool* obstructionMap)
{
	return findPath(start, goal, obstructionMap)[0];
}

