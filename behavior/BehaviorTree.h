#pragma once
#include <vector>
#include "BehaviorNode.h"
#include "../load/LoadFile.h"
#include "../manager/EntityManager.h"

class BehaviorTree : public LoadFile
{
	std::vector<std::string> commands;
	Behavior::Node::Navigator navigator;
	typedef std::pair<std::string, std::string> StringPair;
	Behavior::Node* root = NULL;
	Behavior::Node* newNode = NULL;
	std::vector<Behavior::Node*> tree;
	std::vector<StringPair> parentChildMap;

	Behavior::Node* findNode(std::string name);
	void printNode(Behavior::Node* node, int depth);
	void link();
	void parseCommand(Behavior::Node* node, std::string type);

public:
	BehaviorTree();
	~BehaviorTree();
	Behavior::Node* cur = NULL;
	void store(std::string name, std::string type);
	void printTree();
	void update();
	void init();
	Behavior::Node* getRoot() { return root; }
};

