#include "BehaviorTree.h"
#include "Leaf.h"
#include "Decorator.h"
#include "Composite.h"

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
	for (int i = 0; i < node->getChildCount(); i++)
		printNode(&node->getChild(i), depth);
}

void BehaviorTree::printTree()
{
	printNode(root, 0);
}

void BehaviorTree::postLoad()
{
	link();
	cur = root;
}

void BehaviorTree::process()
{

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
	if (!tree.empty())
		for (int i = 0; i < parentChildMap.size(); i++)
		{
			parentName = parentChildMap[i].first;
			childName = parentChildMap[i].second;
			parent = findNode(parentName);
			for (int j = 0; j < tree.size(); j++)
			{
				child = tree[j];
				if (child->name == childName)
					parent->addChild(*child);
			}
		}
}

void BehaviorTree::store(std::string name, std::string data)
{
	if (name == "leaf")
	{
		if (data == "move")
			newNode = new Leaf(Task::Move());
		else if (data == "objectpush")
			newNode = new Leaf(Task::Push());
		else if (data == "objectpull")
			newNode = new Leaf(Task::Pull());
		else if (data == "objectpickup")
			newNode = new Leaf(Task::Pickup());
		else if (data == "objectdrop")
			newNode = new Leaf(Task::Drop());
		else if (data == "objecttrigger")
			newNode = new Leaf(Task::Trigger());
		tree.push_back(newNode);
	}
	else if (name == "decorator")
	{
		if (data == "invert")
			newNode = new Invert();
		else if (data == "repeat")
			newNode = new Repeat();
		else if (data == "untilfail")
			newNode = new UntilFail();
		else if (data == "untilsuccess")
			newNode = new UntilSuccess();
		else if (data == "alwaysfail")
			newNode = new AlwaysFail();
		else if (data == "alwayssucceed")
			newNode = new AlwaysSucceed();
		tree.push_back(newNode);
	}
	else if (name == "composite")
	{
		if (data == "selector")
			newNode = new Selector();
		else if(data == "sequence")
			newNode = new Sequence();
		//TODO: Impliment
		//else if(data == "random")
		//	newNode = SELECTOR_RANDOM;
		tree.push_back(newNode);
	}
	else if (newNode != NULL)
	{
		if (name == "name")
		{
			newNode->name = data;
		}
		else if (name == "child")
		{
			parentChildMap.push_back(StringPair(newNode->name, data));
		}
	}
}