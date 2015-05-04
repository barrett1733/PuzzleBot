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

void Leaf::run(Navigator& nav)
{
	if(!action->run())
		stop(nav);
}