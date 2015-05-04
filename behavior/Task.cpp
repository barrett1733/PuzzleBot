#include "Task.h"
#include "../pathfinding/pathfinder.h"
#include "../config/Config.h"

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

void Move::createPath(GridBool &grid)
{
	if (path.empty())
	{
		Position start = entity->position;
		Position goal = target->position;
		start.round();
		goal.round();
		pathfinder = new Pathfinding::Pathfinder(grid.getWidth(), grid.getHeight());
		path = pathfinder->findPath(start, goal, &grid);
	}
}

bool Move::run()
{
	init();
	GridBool &grid = *levelManager->getLevel(0);
	createPath(grid);
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
		return false;
	}
	return true;
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
		return false;
	return true;
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
		return false;
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