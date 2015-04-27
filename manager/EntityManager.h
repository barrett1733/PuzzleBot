#pragma once
#include <vector>
#include "../utility/entity.h"
class EntityManager
{
	std::vector<Entity> entities;
	//std::vector<Entity> robots;
public:
	Entity robot;
	Entity& getEntity(Position pos);
	void addEntity(Entity entity);
};

