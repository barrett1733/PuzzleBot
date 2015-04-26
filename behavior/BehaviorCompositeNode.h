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
		std::vector<Node*> children;
		Node* getChild() { return NULL; }
		void addChild(Node* node) { children.push_back(node); }
		bool process() { return 0; }
	};
	typedef CompositeNode CNode;
}
