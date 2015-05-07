#pragma once
#include "BehaviorNode.h"
#include "Task.h"

class Leaf :
	public Behavior::Node
{
	void preRun();
	void run(Navigator&);
public:
	~Leaf();
	void addChild(Node& node);
	Node& getChild(int);
	int getChildCount();
};
