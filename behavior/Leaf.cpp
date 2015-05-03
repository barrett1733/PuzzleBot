#include "Leaf.h"
#include <iostream>

using namespace Behavior;
void Leaf::addChild(Node& node)
{
}

Node& Leaf::getChild()
{
	throw "Assigning child to Leaf: " + name;
}

int Leaf::getChildCount()
{
	return 0;
}

bool Leaf::running(Navigator& nav)
{

}