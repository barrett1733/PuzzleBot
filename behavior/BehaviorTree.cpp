#include "BehaviorTree.h"
#include "Leaf.h"
#include "Decorator.h"
#include "Composite.h"
#include "Task.h"
#include "TaskAction.h"
#include "TaskConditional.h"
#include "TaskState.h"

using namespace Behavior;
BehaviorTree::BehaviorTree()
{
	commands = {
		"moveto",
		"push",
		"pull",
		"pickup",
		"drop",
		"isatlocation",
		"canmoveto",
		"checkbarrier",
		"checkvisible",
		"barrieron",
		"barrieroff",
		"visibleon",
		"visibleoff",

		"invert",
		"repeat",
		"untilfail",
		"untilsuccess",
		"alwaysfail",
		"alwayssucceed",

		"selector",
		"sequence",
	};
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

void BehaviorTree::init()
{
	link();
	cur = root;
	root->start(navigator);
}

void BehaviorTree::update()
{
	if (!navigator.empty())
		navigator.top()->run(navigator);
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

void BehaviorTree::parseCommand(Node* newNode, std::string str)
{
	std::string entity, command, target;
	for (int i = 0; i < commands.size(); i++)
	{
		size_t pos = str.find(commands[i]);
		if (pos != std::string::npos)
		{
			entity = str.substr(0, pos);
			command = str.substr(pos, commands[i].length());
			target = str.substr(commands[i].length() + pos, str.length());
			//std::cout << entity << " : " << command << " : " << target << std::endl;
		}
	}
	if (command == "moveto")
		newNode->action = new Task::Move();
	else if (command == "push")
		newNode->action = new Task::Push();
	else if (command == "pull")
		newNode->action = new Task::Pull();
	else if (command == "pickup")
		newNode->action = new Task::Pickup();
	else if (command == "drop")
		newNode->action = new Task::Drop();
	else if (command == "isatlocation")
		newNode->action = new Task::IsAtLocation();
	else if (command == "checkbarrier")
		newNode->action = new Task::CheckBarrier();
	else if (command == "checkvisible")
		newNode->action = new Task::CheckVisible();
	else if (command == "canmoveto")
		newNode->action = new Task::CanMoveTo();
	else if (command == "barrieron")
		newNode->action = new Task::BarrierOn();
	else if (command == "barrieroff")
		newNode->action = new Task::BarrierOff();
	else if (command == "visibleon")
		newNode->action = new Task::VisibleOn();
	else if (command == "visibleoff")
		newNode->action = new Task::VisibleOff();

	newNode->action->entityName = entity;
	newNode->action->targetName = target;
	newNode->name = str;
}

void BehaviorTree::store(std::string name, std::string data)
{
	if (name == "leaf")
	{
		newNode = new Leaf();
		tree.push_back(newNode);
		parseCommand(newNode, data);
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