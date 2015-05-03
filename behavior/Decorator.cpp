#include "Decorator.h"

using namespace Behavior;
void Decorator::addChild(Node& node)
{
	child = &node;
}

Node& Decorator::getChild()
{
	return *child;
}

int Decorator::getChildCount()
{
	return child == NULL ? 0 : 1;
}

bool Invert::running(Navigator& nav)
{
	child->start(nav);
	result = !child->getResult();
	return true;
}

bool Repeat::running(Navigator& nav)
{
	child->start(nav);
	result = child->getResult();
	return false;
}

bool UntilFail::running(Navigator& nav)
{
	child->start(nav);
	result = child->getResult();
	return result ? false : true;
}

bool UntilSuccess::running(Navigator& nav)
{
	child->start(nav);
	result = child->getResult();
	return result ? true : false;
}

bool AlwaysFail::running(Navigator& nav)
{
	child->start(nav);
	result = false;
	return true;
}

bool AlwaysSucceed::running(Navigator& nav)
{
	child->start(nav);
	result = true;
	return true;
}

