#include "BehaviorNode.h"

using namespace Behavior;

bool Node::getResult()
{
	return result;
}

bool Node::isRunning()
{
	return running;
}

void Node::start(Navigator& nav)
{
	if (nav.empty() || nav.top() != this)
	{
		nav.push(this);
		preRun();
	}
	run(nav);
}

void Node::stop(Navigator& nav)
{
	nav.pop();
	postRun();
}
