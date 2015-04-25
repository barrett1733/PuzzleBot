#pragma once
#include "BehaviorNode.h"
#include <vector>
/*
*	Composite Nodes
*	One parent - many children
*	Children retrieval orders
*		Forward/Backward Sequential, Random
*/

namespace Behavior
{
	class CompositeNode : public Node
	{
	public:
		enum ChildOrderFlags
		{
			FORWARD,
			RANDOM,
			BACKWARD,
			UNTILTRUE,
			UNTILFALSE,
		};
		std::vector<Node*> child;
		Node* getChild() { return NULL; }
		bool update() { return false; }
	};
}
