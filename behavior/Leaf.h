#pragma once
#include "BehaviorNode.h"
#include "Task.h"

class Leaf :
	public Behavior::Node
{
	bool running(Navigator&);
public:
	Leaf(Task::Action action) : action(action) {}
	Task::Action action;
	void addChild(Node& node);
	Node& getChild(int);
	int getChildCount();
};
