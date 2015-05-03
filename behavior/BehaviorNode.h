#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>

namespace Behavior
{
	typedef std::stack<Node*> Navigator;

	class Node
	{
	protected:
		bool result;
		virtual void preRun();
		virtual bool running(Navigator&);
		virtual void postRun();
	public:
		std::string name;
		virtual void addChild(Node& node);
		virtual Node& getChild(int);
		virtual int getChildCount();

		bool getResult();
		void start(Navigator&);

		friend std::ostream& operator<<(std::ostream& os, const Node& node)
		{
			os << node.name << " " << " " << node.nodeAction << " " << node.target << std::endl;
			return os;
		}
	};
}
