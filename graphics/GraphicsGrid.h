#pragma once
#include <SFML\Graphics.hpp>

namespace Graphics
{
	class Grid : public sf::RectangleShape
	{
		
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	public:
		sf::Vector2i amt;
		Grid();
		Grid(sf::Vector2f pos, sf::Vector2f size, sf::Vector2i amt);
	};
}