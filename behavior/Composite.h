#pragma once
#include "BehaviorNode.h"
class Composite :
	public Behavior::Node
{
protected:
	int curChild;
	std::vector<Node*> childNodes;
	void preRun();
public:
	void addChild(Node& node);
	Node& getChild(int);
	int getChildCount();
};

class Selector : public Composite
{
	void run(Navigator&);
}; 

class Sequence : public Composite
{
	void run(Navigator&);
};