#include "obstruction-map.h"

ObstructionMap::ObstructionMap(int size_x, int size_y) :
	Grid<ObstructionType>(size_x, size_y)
{ 
	for (int x = 0; x < size_x; x++)
		for (int y = 0; y < size_y; y++)
			at(x, y) = OT_EMPTY;
}

bool ObstructionMap::isObstructed(Position position)
{
	return at(position) == OT_OBSTRUCTED;
}

bool ObstructionMap::isConsidered(Position position)
{
	return at(position) == OT_CONSIDERED;
}

bool ObstructionMap::isOpen(Position position)
{
	return at(position) == OT_EMPTY;
}
