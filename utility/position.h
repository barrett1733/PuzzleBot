#pragma once

#include <math.h>
#include <iostream>

enum
{
	D_NONE  = 0x00,
	D_UP    = 0x01,
	D_RIGHT = 0x02,
	D_DOWN  = 0x04,
	D_LEFT  = 0x08,
	D_NORTH = 100,
	D_EAST,
	D_SOUTH,
	D_WEST,
	D_NORTH_EAST,
	D_SOUTH_EAST,
	D_NORTH_WEST,
	D_SOUTH_WEST,
	D_COUNT,
};
typedef int Direction;

class Position
{
	//Creation and moving of a position forces sanity
	//Setting checks sanity
	void forceSanity();
	bool checkSanity(float x, float y);

public:
	float x;
	float y;

	Position();
	Position(float x, float y);
	Position(const Position &);

	Position& operator= (const Position &);

	bool checkSanity();

	void moveUnchecked(Direction); // move without forceSanity()
	void moveUnchecked(Direction, float distance);

	void move(Direction);
	void move(Direction, float distance);

	double distance(const Position&);

	Position getNeighbor(Direction);

	bool setX(float x);
	bool setY(float y);
	bool set(float x, float y);
	bool set(Position);
	float getX();
	float getY();

	friend bool operator==(const Position& a, const Position& b)
	{
		if ((a.x == b.x) && (a.y == b.y))
			return true;
		return false;
	}

	friend bool operator<(const Position& a, const Position& b)
	{
		if ((a.x < b.x) && (a.y < b.y))
			return true;
		return false;
	}
	friend bool operator>(const Position& a, const Position& b)
	{
		return !(a < b);
	}

	friend bool operator!=(const Position& a, const Position& b)
	{
		return !(a == b);
	}

	friend std::ostream& operator<< (std::ostream & os, const Position & position)
	{
		os << "(" << position.x << ", " << position.y << ")";
		return os;
	}

	static float max_x;
	static float max_y;
};

