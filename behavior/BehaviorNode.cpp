#include "BehaviorNode.h"

using namespace Behavior;

Node* Node::searchChild(std::string name_)
{
	if (name == name_)
		return this;
	else
	{
		for (int i = 0; i < childNodes.size(); i++)
		{
			if (childNodes[i]->searchChild(name_) != NULL)
				return childNodes[i]->searchChild(name_);
			else
				return NULL;
		}
	}
}

void Node::addChild(Node* node)
{
	childNodes.push_back(node);
}

bool Node::process()
{
	return 0;
}