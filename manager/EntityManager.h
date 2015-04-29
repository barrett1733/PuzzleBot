#pragma once
#include <map>
#include "../utility/entity.h"
#include "../load/LoadFile.h"

class EntityManager : public LoadFile
{
	typedef std::map<std::string, Entity> EntityMap;
	typedef std::map<std::string, Entity>::iterator EntityMapIter;
	std::string entityName;
	EntityMap entities;

public:
	Entity& getEntity(std::string name);
	void addEntity(std::string name, Entity entity);
	void store(std::string, std::string);
};

