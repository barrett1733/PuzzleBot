#include "DisplayGrid.h"

DisplayGrid::ColorIdMap DisplayGrid::GridColors;

DisplayGrid::DisplayGrid()
{
	loadColors();
}

DisplayGrid::DisplayGrid(GridBool* obsMap) : obsMap(obsMap)
{
	loadColors();
}

DisplayGrid::~DisplayGrid()
{}

void DisplayGrid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	int amtX = obsMap->getWidth();
	int amtY = obsMap->getHeight();
	int sizeX = getSize().x;
	int sizeY = getSize().y;
	int tileX, tileY;
	sf::Vector2f tileSize(sizeX / amtX, sizeY / amtY);
	sf::RectangleShape tile(tileSize);
	sf::Vector2f pos = getPosition();
	for (int x = 0; x < amtX; x++)
	{
		for (int y = 0; y < amtY; y++)
		{
			tileX = pos.x + tileSize.x * x;
			tileY = pos.y + tileSize.y * y;
			tile.setPosition(tileX, tileY);
			tile.setFillColor(getTileColor(obsMap->at(x, y)));
			tile.setOutlineColor(getOutlineColor());
			tile.setOutlineThickness(getOutlineThickness());
			target.draw(tile);
		}
	}
}

sf::Color DisplayGrid::getTileColor(bool obsType) const
{
	if (obsType)
	{
		return GridColors["Obs"];
	}
	else
	{
		return GridColors["Emp"];
	}
}

void DisplayGrid::loadColors()
{
	if (GridColors.size() != 3)
	{
		GridColors["Obs"] = sf::Color::Blue;
		GridColors["Emp"] = sf::Color::White;
	}
}

void DisplayGrid::setGrid(GridBool* grid)
{
	obsMap = grid;
}