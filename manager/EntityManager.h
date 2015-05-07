#pragma once
#include <map>
#include "../utility/entity.h"
#include "../load/LoadFile.h"
#include "../load/AdditionalParsing.h"

class EntityManager : public LoadFile, public AdditionalParsing
{
	typedef std::map<std::string, Entity> EntityMap;
	typedef std::map<std::string, Entity>::iterator EntityMapIter;
	std::string entityName;
	EntityMap entities;

public:
	EntityManager() : heldItem("") {}
	std::string heldItem;
	Entity& getEntity(std::string name);
	std::vector<Position> blockedPositions();
	void addEntity(std::string name, Entity entity);
	void store(std::string, std::string);
};

