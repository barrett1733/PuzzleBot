#include "BehaviorTree.h"

using namespace Behavior;
BehaviorTree::BehaviorTree()
{
}

BehaviorTree::~BehaviorTree()
{
	for (int j = 0; j < tree.size(); j++)
	{
		delete tree[j];
		tree[j] = NULL;
	}
}

void BehaviorTree::printNode(Node* node, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		std::cout << "  ";
	}
	std::cout << *node;
	depth++;
	for (int i = 0; i < node->childNodes.size(); i++)
		printNode(node->childNodes[i], depth);
}

void BehaviorTree::printTree()
{
	printNode(root, 0);
}

void BehaviorTree::postLoad()
{
	link();
}

Node* BehaviorTree::findNode(std::string name)
{
	for (int i = 0; i < tree.size(); i++)
	{
		if (name == tree[i]->name)
			return tree[i];
	}
	return NULL;
}

void BehaviorTree::link()
{
	std::string parentName, childName;
	Node *parent, *child;
	root = tree[0];
	for (int i = 0; i < parentChildMap.size(); i++)
	{
		parentName = parentChildMap[i].first;
		childName = parentChildMap[i].second;
		parent = findNode(parentName);
		for (int j = 0; j < tree.size(); j++)
		{
			child = tree[j];
			if (child->name == childName)
				parent->addChild(child);
		}
	}
}

void BehaviorTree::store(std::string name, std::string data)
{
	if (name == "name")
	{
		newNode = new Node();
		newNode->name = data;
		tree.push_back(newNode);
	}
	else if (newNode != NULL)
	{
		if (name == "action")
		{
			if (data == "moveup")
				newNode->action = Action::MOVE_UP;
			else if (data == "movedown")
				newNode->action = Action::MOVE_DOWN;
			else if (data == "moveleft")
				newNode->action = Action::MOVE_LEFT;
			else if (data == "moveright")
				newNode->action = Action::MOVE_RIGHT;
			else if (data == "movetoward")
				newNode->action = Action::MOVE_TOWARD;
			else if (data == "moveaway")
				newNode->action = Action::MOVE_AWAY;
			else if (data == "objectpush")
				newNode->action = Action::OBJECT_PUSH;
			else if (data == "objectpull")
				newNode->action = Action::OBJECT_PULL;
			else if (data == "objectpickup")
				newNode->action = Action::OBJECT_PICKUP;
			else if (data == "objectdrop")
				newNode->action = Action::OBJECT_DROP;
			else
				newNode->action = Action::WAIT;
		}
		else if (name == "child")
		{
			parentChildMap.push_back(StringPair(newNode->name, data));
		}
	}
}