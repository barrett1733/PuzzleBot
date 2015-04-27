#include "ScreenManager.h"
#include "../config/Config.h"

void ScreenManager::init()
{
	gridDisplay = getDefaultView();

	controlDisplay.setViewport(controlPanelViewport);
	controlDisplay.reset(controlPanelRect);

	grid.setPosition(sf::Vector2f(0, 0));
	grid.setSize(sf::Vector2f(gridDisplaySize, gridDisplaySize));
	grid.setOutlineThickness(1);
	grid.setOutlineColor(sf::Color::Black);

	button.setFillColor(sf::Color::Red);
	button.setPosition(controlPanelRect.left + 10, controlPanelRect.top + 10);
	button.setOutlineColor(sf::Color::Black);
	button.setSize(sf::Vector2f(buttonSize, buttonSize));

	robot.setFillColor(sf::Color::Green);
	robot.setRadius(grid.getSize().y / LEVELSIZE / 2);

}

void ScreenManager::eventUpdate(sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			button.setFillColor(sf::Color::Green);
			std::cout << "pressed" << std::endl;
		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			button.setFillColor(sf::Color::Red);
			std::cout << "released" << std::endl;
		}
	}
}

void ScreenManager::render()
{
	grid.setGrid(levelManager->getLevel(0));
	setView(gridDisplay);
	draw(grid);
	draw(robot);
	setView(controlDisplay);
	draw(button);
}

void ScreenManager::update()
{
}

