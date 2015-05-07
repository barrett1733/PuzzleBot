#include "Task.h"
#include "../pathfinding/pathfinder.h"
#include "../config/Config.h"

using namespace Task;
EntityManager* Action::entityManager = NULL;
LevelManager* Action::levelManager = NULL;

void Action::loadObjects()
{
	if (entityName != "")
		entity = &entityManager->getEntity(entityName);
	if (targetName != "")
		target = &entityManager->getEntity(targetName);
	//grid = levelManager->getLevel(0);
	grid = levelManager->getObsMap();
}

void Move::preRun()
{
	loadObjects();
	entity->position.round();
	target->position.round();
	pathfinder = new Pathfinding::Pathfinder(grid->getWidth(), grid->getHeight());
	path = pathfinder->findPath(entity->position, target->position, grid);
}

bool Move::run()
{
	// moving - next position reached
	if (EuclideanDistance(entity->position, nextPos) <= entity->speed)
	{
		path.erase(path.begin());
	}
	// moving - if there are more positions to travel to
	if (!path.empty())
	{
		nextPos = *path.begin();
		entity->moveTowards(nextPos);
	}
	// position reached
	if (path.empty())
	{
		entity->position.round();
		target->position.round();

		return false;
	}
	return true;
}

void Push::preRun()
{
	loadObjects();
	entity->position.round();
	target->position.round();
	entity->target = target->position;
	target->target = target->position.getNeighbor(entity->position.getDirection(entity->target));
}

bool Push::run()
{
	//some kind of rounding issue or something here
	float distEntity = EuclideanDistance(entity->position, entity->target);
	float distTarget = EuclideanDistance(target->position, target->target);

	entity->move();
	target->move();

	if (distEntity <= entity->speed && distTarget <= target->speed)
	{
		entity->position.round();
		target->position.round();

		return false;
	}
	return true;
}

void Pull::preRun()
{
	loadObjects();
	entity->position.round();
	target->position.round();
	target->target = entity->position;
	Direction dir = target->position.getDirection(target->target);
	entity->target = entity->position.getNeighbor(dir);
}

bool Pull::run()
{
	//some kind of rounding issue or something here
	float distEntity = EuclideanDistance(entity->position, entity->target);
	float distTarget = EuclideanDistance(target->position, target->target);

	entity->move();
	target->move();

	if (distEntity <= entity->speed && distTarget <= target->speed)
	{
		entity->position.round();
		target->position.round();

		return false;
	}
	return true;
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