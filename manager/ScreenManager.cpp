#include "ScreenManager.h"


ScreenManager::ScreenManager()
{
}


ScreenManager::~ScreenManager()
{
}


void ScreenManager::init()
{
	gridDisplay = getDefaultView();

	int windowX = getSize().x;
	int windowY = getSize().y;
	const int controlPanelWidth = 200;

	sf::FloatRect controlPanelRect(windowX - controlPanelWidth, 0, controlPanelWidth, windowY);
	float controlPanelSize = (float)controlPanelWidth / windowX;

	controlDisplay.setViewport(sf::FloatRect(1 - controlPanelSize, 0, controlPanelSize, 1));
	controlDisplay.reset(controlPanelRect);

	levels.loadLevels();

	grid.setGrid(levels.getLevel(0));
	grid.setPosition(sf::Vector2f(0, 0));
	grid.setSize(sf::Vector2f(600, 600));
	grid.setOutlineThickness(1);
	grid.setOutlineColor(sf::Color::Black);
}

void ScreenManager::update()
{

}
