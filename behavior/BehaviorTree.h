#pragma once
#include <vector>
#include "BehaviorNode.h"
#include "../load/LoadFile.h"
#include "NodeProcessor.h"

class BehaviorTree : public LoadFile, public NodeProcessor
{
	std::stack<Node*> navigator;
	typedef std::pair<std::string, std::string> StringPair;
	Behavior::Node* root = NULL;
	Behavior::Node* newNode = NULL;
	std::vector<Behavior::Node*> tree;
	std::vector<StringPair> parentChildMap;
	std::string nodeName;

	Behavior::Node* findNode(std::string name);
	void printNode(Behavior::Node* node, int depth);
	void postLoad();

public:
	BehaviorTree();
	~BehaviorTree();
	Behavior::Node* cur = NULL;
	void store(std::string name, std::string type);
	void link();
	void printTree();
	void process();
	Behavior::Node* getRoot() { return root; }
};

