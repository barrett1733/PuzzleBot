#include "DisplayControlPanel.h"
#include <SFML\Graphics.hpp>
#include <iostream>

DisplayControlPanel::DisplayControlPanel()
{
	button.setFillColor(sf::Color::Red);
	button.setPosition(10, 10);
	button.setOutlineColor(sf::Color::Black);
	button.setSize(sf::Vector2f(100, 100));
	if (!font.loadFromFile("res/arial.ttf"))
	{
		std::cerr << "Font file not found..." << std::endl;
	}
	robotCurPos.setPosition(sf::Vector2f(10, 130));
	robotNextPos.setPosition(sf::Vector2f(10, 150));
	robotCurPos.setColor(sf::Color::White);
	robotNextPos.setColor(sf::Color::White);
	robotCurPos.setFont(font);
	robotNextPos.setFont(font);
	robotCurPos.setCharacterSize(12);
	robotNextPos.setCharacterSize(12);
}


DisplayControlPanel::~DisplayControlPanel()
{
}

void DisplayControlPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(button);
	target.draw(robotCurPos);
	target.draw(robotNextPos);
}