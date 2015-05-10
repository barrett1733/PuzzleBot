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
		if ((*iter).second.barrier)
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
	else if (name == "barrier")
	{
		if (data == "true")
			entities[entityName].barrier = true;
		else
			entities[entityName].barrier = false;
	}
	else if (name == "visible")
	{
		if (data == "true")
			entities[entityName].visible = true;
		else
			entities[entityName].visible = false;
	}
}