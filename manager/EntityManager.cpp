#include "EntityManager.h"


EntityManager::EntityManager()
{
	entities.reserve(100);
}


Entity& EntityManager::getEntity(Position pos)
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i].position == pos)
			return entities[i];
	}
}

void EntityManager::addEntity(Entity entity)
{
	entities.push_back(entity);
}