#pragma once

#include "../utility/position.h"
#include "../utility/grid.h"

enum ObstructionType
{
	OT_EMPTY,
	OT_OBSTRUCTED,
	OT_CONSIDERED
};

class ObstructionMap : public Grid<ObstructionType>
{
public:
	ObstructionMap(int size_x, int size_y);

	bool isObstructed(Position);
	bool isConsidered(Position);
	bool isOpen(Position);

	friend std::ostream& operator<<(std::ostream & os, const ObstructionMap & map)
	{
		for (int y = 0; y < map.getHeight(); y++)
		{
			for (int x = 0; x < map.getWidth(); x++)
			{
				if (map.at(x, y) == OT_EMPTY)
					os << ".";
				else if (map.at(x, y) == OT_OBSTRUCTED)
					os << "X";
				else if (map.at(x, y) == OT_CONSIDERED)
					os << "o";
			}
			os << std::endl;
		}
		return os;
	}
};
