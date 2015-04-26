#pragma once
#include "BehaviorNode.h"
/*
*	Decorator Nodes
*	One parent - one child
*	Children retrieval orders
*		Forward/Backward Sequential, Random
*/

namespace Behavior
{
	class DecoratorNode : public Node
	{
		Node* child;
	public:
		Node* getChild(){ return child; }
		void addChild(Node* node) { child = node; }
		bool process() { return 0; }
	};
	typedef DecoratorNode DNode;
}
