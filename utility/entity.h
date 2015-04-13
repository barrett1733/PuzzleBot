#pragma once

#include <string>
#include <vector>
#include "position.h"

class Entity 
{
protected:
	Position position;

public:
	Entity(Position);
	Entity(const Entity&);
	Entity();

	Entity& operator= (const Entity&);

	Position getPosition() const;

	void setPosition(Position);

	friend std::ostream& operator<< (std::ostream & os, const Entity & entity)
	{
		os << entity.position;
		return os;
	}
};
