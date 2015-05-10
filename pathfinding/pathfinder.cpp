#include "pathfinder.h"
#include "../config/Config.h"

using namespace Pathfinding;
double Pathfinder::heursticCost(Position a, Position b)
{
	return ManhattanDistance(a, b);
}

double Pathfinder::pathCost(Position a, Position b)
{
	return EuclideanDistance(a, b);
}

void Pathfinder::init(int x, int y)
{
	size_x = x; 
	size_y = y;
	indexGrid.init(x, y);
}

bool Pathfinder::pathExists(Position start, Position goal, GridBool* obsMap)
{
	goalReached = false;

	indexGrid.add(Node(start, NULL, 0, heursticCost(neighborPos, goal)));

	searchList.push(&indexGrid.get(start));

	curNode = NULL;

	while (!goalReached)
	{
		if (searchList.empty())
			return false;

		curNode = searchList.pop();

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
				if (neighborPos.checkSanity(obsMap->getWidth(), obsMap->getHeight()) && obsMap->at(neighborPos) == false)
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
	return true;
}

Path Pathfinder::findPath(Position start, Position goal, GridBool* obsMap)
{
	goalReached = false;

	indexGrid.add(Node(start, NULL, 0, heursticCost(neighborPos, goal)));

	searchList.push(&indexGrid.get(start));

	closestToGoalNode = &indexGrid.get(start);
	curNode = NULL;

	while (!goalReached)
	{
		if (searchList.empty())
			return constructPath(closestToGoalNode, obsMap->getWidth(), obsMap->getHeight());

		curNode = searchList.pop();

		// this is questionable
		if (curNode->hcost < closestToGoalNode->hcost)
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
				if (neighborPos.checkSanity(obsMap->getWidth(), obsMap->getHeight()) && obsMap->at(neighborPos) == false)
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
	return constructPath(curNode, obsMap->getWidth(), obsMap->getHeight());
}

// Does not include original position
Path Pathfinder::constructPath(Node* goal, int sizex, int sizey)
{
	Node* node = goal;
	Path path;
	path.reserve(sizex * sizey);

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

void Pathfinder::clear()
{
	searchList.clear();
	indexGrid.clear();
}

Position Pathfinder::findNextPosition(Position start, Position goal, GridBool* obstructionMap)
{
	return findPath(start, goal, obstructionMap)[0];
}

