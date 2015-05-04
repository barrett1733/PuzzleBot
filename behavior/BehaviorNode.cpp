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
		std::cout << "Push: " << *this << std::endl;
		running = true;
		nav.push(this);
		preRun();
	}
}

void Node::stop(Navigator& nav)
{
	std::cout << "Pop: " << *this << std::endl;
	nav.pop();
	running = false;
	postRun();
}
