#include "position.h"

Position::Position() : x(0), y(0)
{ }

Position::Position(float x, float y) : x(x), y(y)
{ }

Position::Position(const Position & position) :
	x(position.x),
	y(position.y)
{ }

bool Position::checkSanity(float max_x, float max_y)
{
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= max_x) return false;
	if (y >= max_y) return false;
	return true;
}

Position& Position::operator= (const Position & position)
{
	x = position.x;
	y = position.y;
	return *this;
}

void Position::move(Direction direction)
{
	move(direction, 1);
}

void Position::move(Direction direction, float distance)
{
	if (direction < D_NORTH || direction > D_COUNT)
	{
		if (direction & D_UP)    y -= distance;
		if (direction & D_RIGHT) x += distance;
		if (direction & D_DOWN)  y += distance;
		if (direction & D_LEFT)  x -= distance;
	}
	else
	{
		switch (direction)
		{
		case D_NORTH:	y -= distance; break;
		case D_EAST:	x += distance; break;
		case D_SOUTH:	y += distance; break;
		case D_WEST:	x -= distance; break;
		case D_NORTH_EAST: y -= distance; x += distance; break;
		case D_SOUTH_EAST: y += distance; x += distance; break;
		case D_SOUTH_WEST: y += distance; x -= distance; break;
		case D_NORTH_WEST: y -= distance; x -= distance; break;
		}
	}
}

Position Position::getNeighbor(Direction dir)
{
	Position pos = *this;
	pos.move(dir);
	return pos;
}

void Position::round()
{
	x = std::round(x);
	y = std::round(y);
}