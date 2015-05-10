#include "TaskAction.h"

using namespace Task;
void Move::init()
{
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
		entity->moveTowards(nextPos, entity->speed);
	}
	// position reached
	if (path.empty())
	{
		entity->position.round();
		target->position.round();

		result = true;
		return false;
	}
	return true;
}

void Push::init()
{
	entity->position.round();
	target->position.round();
	nextEntityPos = target->position;
	nextTargetPos = target->position.getNeighbor(entity->position.getDirection(nextEntityPos));
	//entity->target = target->position;
	//target->target = target->position.getNeighbor(entity->position.getDirection(entity->target));
}

bool Push::run()
{
	entity->moveTowards(nextEntityPos);
	target->moveTowards(nextTargetPos, entity->speed);

	if (EuclideanDistance(entity->position, nextEntityPos) <= entity->speed)
	{
		entity->position.round();
		target->position.round();

		result = true;
		return false;
	}
	return true;
}

void Pull::init()
{
	entity->position.round();
	target->position.round();
	nextTargetPos = entity->position;
	Direction dir = target->position.getDirection(nextTargetPos);
	nextEntityPos = entity->position.getNeighbor(dir);
	//target->target = entity->position;
	//entity->target = entity->position.getNeighbor(dir);
}

bool Pull::run()
{
	entity->moveTowards(nextEntityPos);
	target->moveTowards(nextTargetPos, entity->speed);

	if (EuclideanDistance(entity->position, nextEntityPos) <= entity->speed)
	{
		entity->position.round();
		target->position.round();
		result = true;
		return false;
	}
	return true;
}

bool Pickup::run()
{
	entityManager->heldItem = targetName;
	result = true;
	return false;
}

bool Drop::run()
{
	target->position = entity->position;
	entityManager->heldItem = "";
	result = true;
	return false;
}
