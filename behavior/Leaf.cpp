#include "Leaf.h"
#include <iostream>

using namespace Behavior;
void Leaf::addChild(Node& node)
{
}

Behavior::Node& Leaf::getChild(int i)
{
	throw "Assigning child to Leaf: " + name;
}

int Leaf::getChildCount()
{
	return 0;
}

void Leaf::preRun()
{
	action->preRun();
}

void Leaf::run(Navigator& nav)
{
	if(action->run() == false) // if finished running
		stop(nav);
}