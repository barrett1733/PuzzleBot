#include "distance.h"

float ManhattanDistance(Position node, Position goal)
{
	float dx = abs(node.getX() - goal.getX());
	float dy = abs(node.getY() - goal.getY());
	return dx + dy;
}

float DiagonalDistance(Position node, Position goal)
{
	float dx = abs(node.getX() - goal.getX());
	float dy = abs(node.getY() - goal.getY());
	return std::max(dx, dy);
}

float EuclideanDistance(Position node, Position goal)
{
	float dx = abs(node.getX() - goal.getX());
	float dy = abs(node.getY() - goal.getY());
	return sqrt(dx * dx + dy * dy);
}
