#include "distance.h"

float ManhattanDistance(Position node, Position goal)
{
	float dx = abs(node.x - goal.x);
	float dy = abs(node.y - goal.y);
	return dx + dy;
}

float DiagonalDistance(Position node, Position goal)
{
	float dx = abs(node.x - goal.x);
	float dy = abs(node.y - goal.y);
	return std::max(dx, dy);
}

float EuclideanDistance(Position node, Position goal)
{
	float dx = abs(node.x - goal.x);
	float dy = abs(node.y - goal.y);
	return sqrt(dx * dx + dy * dy);
}
