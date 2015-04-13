#include "GraphicsGrid.h"

namespace Graphics
{

	Grid::Grid() : amt(1, 1)
	{ }

	Grid::Grid(sf::Vector2f pos, sf::Vector2f size, sf::Vector2i amt) : amt(amt)
	{
		setPosition(pos);
		setSize(size);
	};

	void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		sf::Vector2f tileSize(getSize().x / amt.x, getSize().y / amt.y);
		sf::RectangleShape tile(tileSize);
		tile.setFillColor(getFillColor());
		tile.setOutlineColor(getOutlineColor());
		tile.setOutlineThickness(getOutlineThickness());
		for (int x = getPosition().x; x < getSize().x; x += tileSize.x)
			for (int y = getPosition().y; y < getSize().y; y += tileSize.y)
			{
				tile.setPosition(x, y);
				target.draw(tile);
			}
	}

}