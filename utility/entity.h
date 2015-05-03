#pragma once
#include "position.h"

class Entity 
{
	enum EntityType
	{
		NONE,
		DOOR,
		SWITCH,
		ITEM,
		BOX
	};
	void moveTowards(Position);
	void moveTowards(Direction);
public:
	Position position, targetPos;
	float speed;

	Entity(Position position, float speed);
	Entity(const Entity&);
	Entity();

	Entity& operator= (const Entity&);

	void move();

	friend std::ostream& operator<< (std::ostream & os, const Entity & entity)
	{
		os << entity.position << " " << entity.speed;
		return os;
	}
};
