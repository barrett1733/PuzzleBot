#pragma once
#include "BehaviorNode.h"
#include "Task.h"

class Leaf :
	public Behavior::Node
{
	bool running(Navigator&);
public:
	Task::Action action;
	void addChild(Node& node);
	Node& getChild();
	int getChildCount();
};
