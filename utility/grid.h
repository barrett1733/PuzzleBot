#pragma once

#include "position.h"

/*
	A single array is much faster than a 2D array.
	SB - 4/10/2015
*/

template <typename T>
class Grid
{
	int sizeX, sizeY;
	T * grid;

public:
	Grid() : grid(NULL), sizeX(0), sizeY(0)  {}
	Grid(int x, int y) : grid(NULL) { alloc(x, y); }
	~Grid() { dealloc(); }
	Grid(Grid& grid) : grid(NULL)
	{
		alloc(grid.getWidth(), grid.getHeight());
		for (int x = 0; x < grid.getWidth(); x++)
			for (int y = 0; y < grid.getHeight(); y++)
				at(x, y) = grid.at(x, y);
	}

	int getWidth() const { return sizeX; }
	int getHeight() const { return sizeY; }
	

	void alloc(int x, int y)
	{
		if (!grid)
		{
			sizeX = x;
			sizeY = y;
			grid = new T[sizeX * sizeY];
		}
	}

	void dealloc()
	{
		if (grid)
		{
			delete[] grid;
			grid = NULL;
		}
	}

	void clear(T t)
	{
		for (int i = 0; i < sizeX * sizeY; i++)
			grid[i] = t;
	}

	T& at(Position pos)
	{
		return at(pos.x, pos.y);
	}

	T& at(int x, int y)
	{
		if (x >= 0 && x < sizeX && y >= 0 && y < sizeY)
			return grid[x * sizeY + y];
		else
			throw std::out_of_range("Grid<>::at() : Out of Range");
	}

	const T& at(Position pos) const
	{
		return at(pos.x, pos.y)
	}

	const T& at(int x, int y) const
	{
		if (x >= 0 && x < sizeX && y >= 0 && y < sizeY)
			return grid[x * sizeY + y];
		else
			throw std::out_of_range("Grid<>::at() : Out of Range");
	}
};

typedef Grid<bool> GridBool;
typedef Grid<int> GridInt;
typedef Grid<float> GridFloat;