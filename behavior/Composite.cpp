#include "Composite.h"

using namespace Behavior;

void Composite::addChild(Node& node)
{
	childNodes.push_back(&node);
}

Node& Composite::getChild(int num)
{
	return *childNodes.at(num);
}

int Composite::getChildCount()
{
	return childNodes.size();
}

void Composite::preRun()
{
	curChild = 0;
}

bool Selector::running(Navigator& nav)
{
	childNodes[curChild]->start(nav);
	if (childNodes[curChild]->getResult()) // Selector - finish when child succeeds
	{
		result = true;
		return true;
	}
	else if (curChild >= childNodes.size())
	{
		result = false;
		return true;
	}
	else
		curChild++;
	return false;
}

bool Sequence::running(Navigator& nav)
{
	childNodes[curChild]->start(nav);
	if (!childNodes[curChild]->getResult()) // sequence - finish when child fails
	{
		result = false;
		return false;
	}
	else if (curChild >= childNodes.size())
	{
		result = true;
		return false;
	}
	else
		curChild++;
	return true;
}

