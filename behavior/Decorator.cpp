#include "Decorator.h"

using namespace Behavior;
void Decorator::addChild(Node& node)
{
	child = &node;
}

Node& Decorator::getChild(int i)
{
	return *child;
}

int Decorator::getChildCount()
{
	return child == NULL ? 0 : 1;
}

void Invert::run(Navigator& nav)
{
	child->start(nav);
	if (!child->isRunning())
	{
		result = !child->getResult();
		stop(nav);
	}
}

void Repeat::run(Navigator& nav)
{
	child->start(nav);
	if (!child->isRunning())
	{
		result = child->getResult();
		//stop(nav);
	}
}

void UntilFail::run(Navigator& nav)
{
	child->start(nav);
	if (!child->isRunning())
	{
		result = child->getResult();
		if (result == false) stop(nav);
	}
}

void UntilSuccess::run(Navigator& nav)
{
	child->start(nav);
	if (!child->isRunning())
	{
		result = child->getResult();
		if (result == true) stop(nav);
	}
}

void AlwaysFail::run(Navigator& nav)
{
	child->start(nav);
	if (!child->isRunning())
	{
		result = false;
		stop(nav);
	}
}

void AlwaysSucceed::run(Navigator& nav)
{
	child->start(nav);
	if (!child->isRunning())
	{
		result = true;
		stop(nav);
	}
}

