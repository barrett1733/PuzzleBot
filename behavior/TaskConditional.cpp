#include "TaskConditional.h"

using namespace Task;
bool IsAtLocation::run()
{
	if (entity->position == target->position)
		result = true;
	else
		result = false;
	return false;
}

bool CheckBarrier::run()
{
	result = entity->barrier;
	return false;
}

bool CheckVisible::run()
{
	result = entity->visible;
	return false;
}

void CanMoveTo::init()
{
	entity->position.round();
	target->position.round();
	pathfinder = new Pathfinding::Pathfinder(grid->getWidth(), grid->getHeight());
}

bool CanMoveTo::run()
{
	result = pathfinder->pathExists(entity->position, target->position, grid);
	return false;
}