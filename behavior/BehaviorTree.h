#pragma once
#include <vector>
#include "BehaviorNode.h"
#include "../load/LoadFile.h"

class BehaviorTree : public LoadFile
{
	typedef std::pair<std::string, std::string> StringPair;
	Behavior::Node* root = NULL;
	Behavior::Node* newNode = NULL;
	std::vector<Behavior::Node*> tree;
	std::vector<StringPair> parentChildMap;

	Behavior::Node* findNode(std::string name);
	void printNode(Behavior::Node* node, int depth);
	void postLoad();

public:
	BehaviorTree();
	~BehaviorTree();
	void store(std::string name, std::string type);
	void link();
	void printTree();
	Behavior::Node* getRoot() { return root; }
};

