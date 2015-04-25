#pragma once
#include <vector>
#include "../utility/entity.h"
class EntityManager
{
	std::vector<Entity> entities;
	std::vector<Entity> robots;
public:
	EntityManager();
	Entity& getEntity(Position pos);
	void addEntity(Entity entity);
};

