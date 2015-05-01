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

}

Position ScreenManager::convertPosition(Position pos)
{
	GridBool obs = *levelManager->getLevel(0);
	return Position(pos.x * (gridDisplaySize / obs.getWidth()), pos.y * (gridDisplaySize / obs.getHeight()));
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
	for (sfEntityMapIter iter = sfEntities.begin(); iter != sfEntities.end(); iter++)
	{
		draw(*(*iter).second);
	}
	setView(controlDisplay);
	draw(button);
}

void ScreenManager::update()
{
	for (sfEntityMapIter iter = sfEntities.begin(); iter != sfEntities.end(); iter++)
	{
		Position entityPos = convertPosition(entityManager->getEntity((*iter).first).position);
		(*iter).second->setPosition(entityPos.x, entityPos.y);
	}
}

sf::Shape& ScreenManager::getsfEntity(std::string name)
{
	return *sfEntities[name];
}

void ScreenManager::addsfEntity(std::string name, sf::Shape* sfEntity)
{
	sfEntities[name] = sfEntity;
}

void ScreenManager::store(std::string name, std::string data)
{
	if (name == "name")
	{
		sfEntityName = data;
	}
	else if (name == "shape")
	{
		if (data == "circle")
		{
			sfEntities[sfEntityName] = new sf::CircleShape(grid.getSize().y / LEVELSIZE / 2);
			//possible to set scale instead of set size
			//sfEntities[sfEntityName]->scale(1, 1);
		}
		else if (data == "square")
			sfEntities[sfEntityName] = new sf::RectangleShape(sf::Vector2f(grid.getSize().x / LEVELSIZE, grid.getSize().y / LEVELSIZE));
	}
	else if (name == "scalex")
	{
		sfEntities[sfEntityName]->scale(atof(data.c_str()), 1);
	}
	else if (name == "scaley")
	{
		sfEntities[sfEntityName]->scale(1, atof(data.c_str()));
	}
	else if (name == "color")
	{
		if (data == "green")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Green);
		if (data == "red")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Red);
		if (data == "yellow")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Yellow);
		if (data == "blue")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Blue);
	}
	else if (name == "outlinethickness")
	{
		sfEntities[sfEntityName]->setOutlineThickness(atof(data.c_str()));
	}
}
