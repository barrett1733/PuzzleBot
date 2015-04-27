#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace Behavior
{
	enum Action
	{
		NONE,
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
		std::string name;
		std::vector<Node*> childNodes;
		Action action = NONE;

		Node* searchChild(std::string name_);
		void addChild(Node* node);
		bool process();
		friend std::ostream& operator<<(std::ostream& os, const Node& node)
		{
			os << node.name << std::endl;
			return os;
		}
	};
}
