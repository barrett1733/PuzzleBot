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

void BehaviorTree::link()
{
	root = tree[0];
	for (int i = 0; i < tree.size(); i++)
	{
		for (int j = 0; j < tree.size(); j++)
		{
			if (tree[i]->name == tree[j]->parent)
				tree[i]->addChild(tree[i]);
		}
	}
}

void BehaviorTree::store(std::string name, std::string data)
{
	if (name == "node")
	{
		if (data == "composite")
		{
			newNode = new CompositeNode();
		}
		else if (data == "decorator")
		{
			newNode = new DecoratorNode();
		}
		else if (data == "leaf")
		{
			newNode = new LeafNode();
		}
		if (newNode != NULL)
			tree.push_back(newNode);
	}
	else if (newNode != NULL)
	{
		if (name == "name")
		{
			newNode->name = data;
		}
		else if (name == "action")
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
		else if (name == "parent")
		{
			newNode->parent = data;
		}
	}
}