#pragma once
#include <string>
#include "BehaviorCompositeNode.h"

class BehaviorTree
{
	Behavior::CompositeNode root;
public:
	BehaviorTree();
	~BehaviorTree();
	void loadFromFile(std::string);
	bool checkDelims(std::string);
};

