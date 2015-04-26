#pragma once
#include <vector>
#include "BehaviorCompositeNode.h"
#include "BehaviorDecoratorNode.h"
#include "BehaviorLeafNode.h"
#include "../load/LoadFile.h"

class BehaviorTree : public LoadFile
{
	Behavior::Node* root = NULL;
	Behavior::Node* newNode = NULL;
	std::vector<Behavior::Node*> tree;

	void postLoad() { link(); }
	void link();
public:
	BehaviorTree();
	~BehaviorTree();
	void store(std::string name, std::string type);
	Behavior::Node* getRoot() { return root; }
};

