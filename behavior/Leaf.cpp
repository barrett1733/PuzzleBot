#include "Leaf.h"
#include <iostream>

using namespace Behavior;
void Leaf::addChild(Node& node)
{
}

Node& Leaf::getChild(int i)
{
	throw "Assigning child to Leaf: " + name;
}

int Leaf::getChildCount()
{
	return 0;
}

bool Leaf::running(Navigator& nav)
{
	return action.run();
}