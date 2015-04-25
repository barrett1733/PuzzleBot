#pragma once
#include <SFML\Graphics.hpp>

class DisplayControlPanel : public sf::Drawable
{
	sf::RectangleShape button;
	sf::Text robotCurPos, robotNextPos;
	sf::Font font;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
public:
	DisplayControlPanel();
	~DisplayControlPanel();
};

