#include "Task.h"
#include "../pathfinding/pathfinder.h"
#include "../config/Config.h"

using namespace Task;
EntityManager* Action::entityManager = NULL;
LevelManager* Action::levelManager = NULL;

void Action::preRun()
{
	if (entityName != "")
		entity = &entityManager->getEntity(entityName);
	if (targetName != "")
		target = &entityManager->getEntity(targetName);
	//grid = levelManager->getLevel(0);
	grid = levelManager->getObsMap();
	init();
}

bool Action::getResult()
{
	return result;
}
