#pragma once
#include "BehaviorNode.h"

namespace Behavior
{
	class LeafNode : public Node
	{
	public:
		Node* getChild(){ return NULL; }
		void addChild(Node* node) {}
		bool process() { return 0; }
	};
	typedef LeafNode LNode;
}