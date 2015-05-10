#include "TaskState.h"

using namespace Task;
bool BarrierOn::run()
{
	entity->barrier = true;
	result = true;
	return false;
}

bool BarrierOff::run()
{
	entity->barrier = false;
	result = true;
	return false;
}

bool VisibleOn::run()
{
	entity->visible = true;
	result = true;
	return false;
}

bool VisibleOff::run()
{
	entity->visible = false;
	result = true;
	return false;
}
