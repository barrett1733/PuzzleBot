#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>

namespace Behavior
{

	class Node
	{
	public:
		std::string name;
		typedef std::stack<Node*> Navigator;

	protected:
		bool result;
		virtual void preRun() {}
		virtual bool running(Navigator&) = 0;
		virtual void postRun() {}
	public:
		Node() {};
		virtual void addChild(Node& node) = 0;
		virtual Node& getChild(int) = 0;
		virtual int getChildCount() = 0;

		bool getResult();
		void start(Navigator&);

		friend std::ostream& operator<<(std::ostream& os, const Node& node)
		{
			os << node.name << std::endl;
			return os;
		}
	};
}
