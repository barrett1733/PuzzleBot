#pragma once
#include "BehaviorNode.h"

namespace Behavior
{
	class LeafNode : public Node
	{
	public:
		std::string action;
		Node* getChild(){ return NULL; }
	};
}