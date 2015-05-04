#pragma once
#include "BehaviorNode.h"
#include "Task.h"

class Leaf :
	public Behavior::Node
{
	void run(Navigator&);
public:
	void addChild(Node& node);
	Node& getChild(int);
	int getChildCount();
};
