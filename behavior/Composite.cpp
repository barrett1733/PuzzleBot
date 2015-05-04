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
	if (!childNodes[curChild]->isRunning())
	{
		if (childNodes[curChild]->getResult()) // Selector - finish when child succeeds
		{
			result = true;
			stop(nav);
		}
		curChild++;
		if (curChild >= childNodes.size())
		{
			result = false;
			stop(nav);
		}
	}
}

void Sequence::run(Navigator& nav)
{
	childNodes[curChild]->start(nav);
	if (!childNodes[curChild]->isRunning())
	{
		if (!childNodes[curChild]->getResult()) // sequence - finish when child fails
		{
			result = false;
			stop(nav);
		}
		curChild++;
		if (curChild >= childNodes.size())
		{
			result = true;
			stop(nav);
		}
	}
}

