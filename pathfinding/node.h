#pragma once

#include "../utility/position.h"
#include <iostream>

struct Node {
	Position pos;
	Node* parentNode;
	double gcost, fcost;
	Node() :
		pos(Position(0, 0)),
		parentNode(NULL),
		gcost(0),
		fcost(0)
	{}
	Node(Position pos, Node* parent, double g, double h) :
		pos(pos),
		parentNode(parent),
		gcost(g),
		fcost(g + h)
	{}
	void set(Position pos_, Node* par, double g, double h)
	{
		pos = pos_;
		parentNode = par;
		gcost = g;
		fcost = g + h;
	}
	bool operator== (Node &a) const
	{
		return (pos == a.pos &&
			parentNode == a.parentNode &&
			gcost == a.gcost &&
			fcost == a.fcost);
	}
	Node& operator= (Node& a)
	{
		pos = a.pos;
		parentNode = a.parentNode;
		gcost = a.gcost;
		fcost = a.fcost;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const Node& node)
	{
		if (node.parentNode != NULL)
			os << node.pos << " " << node.parentNode->pos << " G:" << node.gcost << " F:" << node.fcost;
		else
			os << node.pos << " (N,N)" << " G:" << node.gcost << " F:" << node.fcost;
		return os;
	}
};
