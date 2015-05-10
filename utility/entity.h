#pragma once
#include "position.h"

class Entity 
{
public:
	Position position;
	float speed;
	bool barrier, visible;

	Entity(Position position, float speed);
	Entity(const Entity&);
	Entity();

	Entity& operator= (const Entity&);

	void moveTowards(Position, float);
	void moveTowards(Position);
	void moveTowards(Direction, float);
	void moveTowards(Direction);

	friend std::ostream& operator<< (std::ostream & os, const Entity & entity)
	{
		os << entity.position << " " << entity.speed;
		return os;
	}
};
