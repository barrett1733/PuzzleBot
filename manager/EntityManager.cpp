#include "EntityManager.h"


Entity& EntityManager::getEntity(std::string name)
{
	return entities[name];
}

void EntityManager::addEntity(std::string name, Entity entity)
{
	entities[name] = entity;
}

std::vector<Position> EntityManager::blockedPositions()
{
	std::vector<Position> obsVec;
	for (EntityMapIter iter = entities.begin(); iter != entities.end(); iter++)
	{
		if ((*iter).second.type == Entity::BARRIER)
			obsVec.push_back((*iter).second.position);
	}
	return obsVec;
}

void EntityManager::store(std::string name, std::string data)
{
	if (name == "name")
	{
		entities[data] = Entity();
		entityName = data;
	}
	else if (name == "position")
	{
		entities[entityName].position = parseCoords(data);
	}
	else if (name == "speed")
	{
		entities[entityName].speed = atof(data.c_str()) / 100;
	}
	else if (name == "type")
	{
		if (data == "wall")
			entities[entityName].type = Entity::WALL;
		else if (data == "trigger")
			entities[entityName].type = Entity::TRIGGER;
		else if (data == "item")
			entities[entityName].type = Entity::ITEM;
		else if (data == "barrier")
			entities[entityName].type = Entity::BARRIER;
		else
			entities[entityName].type = Entity::NONE;
	}
}