#include "ScreenManager.h"
#include "../config/Config.h"

void ScreenManager::init()
{
	gridDisplay = getDefaultView();

	controlDisplay.setViewport(Config::controlPanelViewport);
	controlDisplay.reset(Config::controlPanelRect);

	grid.setPosition(sf::Vector2f(0, 0));
	grid.setSize(sf::Vector2f(Config::gridDisplaySize, Config::gridDisplaySize));
	grid.setOutlineThickness(1);
	grid.setOutlineColor(sf::Color::Black);

	pauseButton.setFillColor(sf::Color::Green);
	pauseButton.setPosition(Config::controlPanelRect.left + 50, Config::controlPanelRect.top + 10);
	pauseButton.setOutlineColor(sf::Color::Black);
	pauseButton.setSize(sf::Vector2f(Config::buttonSize, Config::buttonSize));

	inventoryBox.setFillColor(sf::Color::Black);
	inventoryBox.setPosition(Config::controlPanelRect.left + 50, Config::controlPanelRect.top + 450);
	inventoryBox.setOutlineColor(sf::Color::White);
	inventoryBox.setOutlineThickness(10);
	inventoryBox.setSize(sf::Vector2f(Config::buttonSize, Config::buttonSize));
}

Position ScreenManager::convertPosition(Position pos)
{
	GridBool obs = *levelManager->getLevel(0);
	return Position(pos.x * (Config::gridDisplaySize / obs.getWidth()), pos.y * (Config::gridDisplaySize / obs.getHeight()));
}

void ScreenManager::eventUpdate(sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (pauseButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		{
			if (!Config::gamePause)
			{
				pauseButton.setFillColor(sf::Color::Red);
				Config::gamePause = true;
			}
			else
			{
				pauseButton.setFillColor(sf::Color::Green);
				Config::gamePause = false;
			}
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
	draw(pauseButton);
	draw(inventoryBox);
}

void ScreenManager::update()
{
	for (sfEntityMapIter iter = sfEntities.begin(); iter != sfEntities.end(); iter++)
	{
		Position entityPos = convertPosition(entityManager->getEntity((*iter).first).position);
		(*iter).second->setPosition(entityPos.x, entityPos.y);

		sf::Shape* object = (*iter).second;
		object->setScale(grid.getSize().x / Config::LEVELSIZE / 100, grid.getSize().y / Config::LEVELSIZE / 100);
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
			sfEntities[sfEntityName] = new sf::CircleShape(50);
		}
		else if (data == "square")
			sfEntities[sfEntityName] = new sf::RectangleShape(sf::Vector2f(100,100));
	}
	else if (name == "color")
	{
		if (data == "green")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Green);
		else if (data == "red")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Red);
		else if (data == "yellow")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Yellow);
		else if (data == "blue")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Blue);
		else if (data == "magenta")
			sfEntities[sfEntityName]->setFillColor(sf::Color::Magenta);
	}
	else if (name == "outlinethickness")
	{
		sfEntities[sfEntityName]->setOutlineThickness(atof(data.c_str()));
	}
}
