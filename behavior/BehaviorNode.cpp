#include "BehaviorNode.h"

using namespace Behavior;

bool Node::getResult()
{
	return result;
}

void Node::start(Navigator& nav)
{
	if (nav.top() != this)
	{
		nav.push(this);
		preRun();
	}
	if (running(nav)) // if true, finished running
	{
		nav.pop();
		postRun();
	}
}
