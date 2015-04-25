#pragma once
#include <string>

namespace Behavior
{
	class Node
	{
		enum ActionFlags
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
		std::string name, status;
		ActionFlags action;
		Node* parent;
	public:
		bool result;
		Node* getParent();
		virtual Node* getChild() = 0;
		virtual bool update() = 0;
	};
}
