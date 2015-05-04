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
	Node& getChild(int);
	int getChildCount();
};

class Invert : public Decorator
{
	void run(Navigator&);
};

class Repeat : public Decorator
{
	void run(Navigator&);
};

class UntilFail : public Decorator
{
	void run(Navigator&);
};

class UntilSuccess : public Decorator
{
	void run(Navigator&);
};

class AlwaysFail : public Decorator
{
	void run(Navigator&);
};

class AlwaysSucceed : public Decorator
{
	void run(Navigator&);
};

