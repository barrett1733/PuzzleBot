#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include "Task.h"

namespace Behavior
{

	class Node
	{
	public:
		std::string name;
		typedef std::stack<Node*> Navigator;

	protected:
		bool result, running;
		virtual void preRun() {}
		virtual void run(Navigator&) = 0;
		virtual void postRun() {}
	public:
		Node() {};
		Task::Action* action;
		virtual void addChild(Node& node) = 0;
		virtual Node& getChild(int) = 0;
		virtual int getChildCount() = 0;

		bool getResult();
		bool isRunning();
		void start(Navigator&);
		void stop(Navigator&);

		friend std::ostream& operator<<(std::ostream& os, const Node& node)
		{
			os << node.name << std::endl;
			return os;
		}
	};
}
