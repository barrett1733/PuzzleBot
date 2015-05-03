#pragma once
#include "BehaviorNode.h"

class Decorator :
	public Behavior::Node
{
protected:
	int curChild;
	Node* child = NULL;
public:
	void addChild(Node& node);
	Node& getChild();
	int getChildCount();
};

class Invert : public Decorator
{
	bool running(Navigator&);
};

class Repeat : public Decorator
{
	bool running(Navigator&);
};

class UntilFail : public Decorator
{
	bool running(Navigator&);
};

class UntilSuccess : public Decorator
{
	bool running(Navigator&);
};

class AlwaysFail : public Decorator
{
	bool running(Navigator&);
};

class AlwaysSucceed : public Decorator
{
	bool running(Navigator&);
};

