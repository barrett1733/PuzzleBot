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

void Selector::run(Navigator& nav)
{
	childNodes[curChild]->start(nav);
	curChild++;
	if (!childNodes[curChild]->isRunning())
	{
		if (childNodes[curChild]->getResult()) // Selector - finish when child succeeds
		{
			result = true;
			stop(nav);
		}
		if (curChild <= childNodes.size())
		{
			curChild = 0;
			result = false;
			stop(nav);
		}
	}
}

void Sequence::run(Navigator& nav)
{
	if (curChild >= (int)childNodes.size())
	{
		result = true;
		stop(nav);
	}
	if (curChild - 1 >= 0)
	{
		if (!childNodes[curChild - 1]->isRunning())
			if (!childNodes[curChild - 1]->getResult()) // sequence - finish when child fails
			{
				result = false;
				stop(nav);
			}
	}
	if (curChild < (int)childNodes.size())
	{
		childNodes[curChild]->start(nav);
		curChild++;
	}
}

