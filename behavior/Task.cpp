#include "Task.h"

using namespace Task;
EntityManager* Action::entityManager = NULL;
LevelManager* Action::levelManager = NULL;

void Action::init()
{
	if (entityName != "")
		entity = &entityManager->getEntity(entityName);
	if (targetName != "")
		target = &entityManager->getEntity(targetName);
}

bool Move::run()
{
	init();
	GridBool &grid = *levelManager->getLevel(0);
	if (!grid.at(target->position))
	{
		entity->targetPos = target->position;
		entity->move();
	}
	if (entity->position == entity->targetPos)
	{
		return true;
	}
	return false;
}

bool Push::run()
{
	init();
	Direction dir = entity->position.getDirection(target->position);
	GridBool &grid = *levelManager->getLevel(0);
	if (!grid.at(target->position.getNeighbor(dir)))
	{
		target->targetPos = target->position.getNeighbor(dir);
		entity->targetPos = target->position;
		entity->move();
		target->move();
	}
	else if (entity->position == entity->targetPos && target->position == target->targetPos)
		return true;
	return false;
}

bool Pull::run()
{
	init();
	Direction dir = entity->position.getDirection(entity->position);
	GridBool &grid = *levelManager->getLevel(0);
	if (!grid.at(entity->position.getNeighbor(dir)))
	{
		entity->targetPos = entity->position.getNeighbor(dir);
		entity->targetPos = entity->position;
		entity->move();
		entity->move();
	}
	else if (entity->position == entity->targetPos && entity->position == entity->targetPos)
		return true;
	return false;
}

bool Pickup::run()
{
	return false;
}

bool Drop::run()
{
	return false;
}

bool Trigger::run()
{
	return false;
}