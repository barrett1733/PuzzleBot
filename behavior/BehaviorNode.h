#pragma once
#include <string>

namespace Behavior
{
	enum Action
	{
		WAIT,
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_TOWARD,
		MOVE_AWAY,
		OBJECT_PUSH,
		OBJECT_PULL,
		OBJECT_PICKUP,
		OBJECT_DROP
	};
	class Node
	{
		bool result = false;
	public:
		std::string name, parent;
		Action action;
		virtual Node* getChild() = 0;
		virtual void addChild(Node*) = 0;
		virtual bool process() = 0;
		friend std::ostream& operator<<(std::ostream& os, const Node& node)
		{
			os << "Name: " << node.name << " Action: " << node.action << " Parent: " << node.parent;
			return os;
		}
	};
}
