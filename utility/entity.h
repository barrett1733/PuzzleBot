#pragma once
#include "position.h"

class Entity 
{
public:
	Position position;
	float speed = 0.5;

	Entity(Position);
	Entity(const Entity&);
	Entity();

	Entity& operator= (const Entity&);

	void moveTowards(Position);

	friend std::ostream& operator<< (std::ostream & os, const Entity & entity)
	{
		os << entity.position;
		return os;
	}
};
