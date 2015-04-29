#include "EntityManager.h"


Entity& EntityManager::getEntity(std::string name)
{
	return entities[name];
}

void EntityManager::addEntity(std::string name, Entity entity)
{
	entities[name] = entity;
}

void EntityManager::store(std::string name, std::string data)
{
	if (name == "name")
	{
		entities[data] = Entity();
		entityName = data;
	}
	else if (name == "positionx")
	{
		entities[entityName].position.x = atof(data.c_str());
	}
	else if (name == "positiony")
	{
		entities[entityName].position.y = atof(data.c_str());
	}
	else if (name == "speed")
	{
		entities[entityName].speed = atof(data.c_str())/100;
	}
}