#include "ScreenManager.h"
#include "../config/Config.h"

ScreenManager::~ScreenManager()
{
	for (int i = 0; i < sfEntities.size(); i++)
	{
		delete sfEntities[i].second->shape;
		sfEntities[i].second->shape = NULL;
	}
}

void ScreenManager::init()
{
	if (!font.loadFromFile("res/arial.ttf"))
	{
		std::cerr << "Font file not found..." << std::endl;
	}

	gridDisplay = getDefaultView();

	controlDisplay.setViewport(Config::controlPanelViewport);
	controlDisplay.reset(Config::controlPanelRect);

	grid.setPosition(sf::Vector2f(0, 0));
	grid.setSize(sf::Vector2f(Config::gridDisplaySize, Config::gridDisplaySize));
	grid.setOutlineThickness(1);
	grid.setOutlineColor(sf::Color::Black);

	pauseButton.setPosition(Config::controlPanelRect.left + 50, Config::controlPanelRect.top + 10);
	pauseButton.setOutlineColor(sf::Color::Black);
	pauseButton.setSize(sf::Vector2f(Config::buttonSize, Config::buttonSize));

	pauseText.setFont(font);
	pauseText.setCharacterSize(20);
	pauseText.setColor(sf::Color::Black);
	pauseText.setPosition(Config::controlPanelRect.left + 60, Config::controlPanelRect.top + 45);

	if (Config::gamePause)
	{
		pauseButton.setFillColor(sf::Color::Red);
		pauseText.setString("Paused");
	}
	else
	{
		pauseButton.setFillColor(sf::Color::Green);
		pauseText.setString("Running");
	}

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
				pauseText.setString("Paused");
				Config::gamePause = true;
			}
			else
			{
				pauseButton.setFillColor(sf::Color::Green);
				pauseText.setString("Running");
				Config::gamePause = false;
			}
		}
	}
}

void ScreenManager::render()
{
	grid.setGrid(levelManager->getLevel(0));
	setView(controlDisplay);
	draw(pauseButton);
	draw(pauseText);
	draw(inventoryBox);

	setView(gridDisplay);
	draw(grid);
	for (int i = sfEntities.size() - 1; i >= 0; i--)
	{
		if (sfEntities[i].second->visible)
		{
			draw(*sfEntities[i].second->shape);
		}
	}
	for (int i = sfEntities.size() - 1; i >= 0; i--)
	{
		if (sfEntities[i].second->visible)
		{
			draw(sfEntities[i].second->text);
		}
	}
}

void ScreenManager::update()
{
	for (int i = 0; i < sfEntities.size(); i++)
	{
		Position entityPos = convertPosition(entityManager->getEntity(sfEntities[i].first).position);
		sfEntities[i].second->shape->setPosition(entityPos.x, entityPos.y);
		sfEntities[i].second->text.setPosition(entityPos.x, entityPos.y);
		sfEntities[i].second->visible = entityManager->getEntity(sfEntities[i].first).visible;

		sf::Shape* object = sfEntities[i].second->shape;
		object->setScale(grid.getSize().x / Config::LEVELSIZE / 100, grid.getSize().y / Config::LEVELSIZE / 100);

	}
	if (entityManager->heldItem != "")
	{
		sfEntityIdMap[entityManager->heldItem].shape->setPosition(Config::inventoryboxPos);
		sfEntityIdMap[entityManager->heldItem].text.setPosition(Config::inventoryboxPos);
	}
}

sf::Shape& ScreenManager::getsfEntity(std::string name)
{
	return *sfEntityIdMap[name].shape;
}

void ScreenManager::addsfEntity(std::string name, sf::Shape* sfEntity)
{
	sfEntityIdMap[name].shape = sfEntity;
	sfEntityIdMap[name].text.setString(name);
	sfEntityIdMap[name].text.setFont(font);
	sfEntityIdMap[name].text.setCharacterSize(12);
	sfEntityIdMap[name].text.setColor(sf::Color::Black);
	sfEntities.push_back(sfEntityPair(name, &sfEntityIdMap[name]));
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
			addsfEntity(sfEntityName, new sf::CircleShape(50));
			//sfEntityIdMap[sfEntityName].shape = new sf::CircleShape(50);
			//sfEntities.push_back(sfEntityPair(sfEntityName, &sfEntityIdMap[sfEntityName]));
		}
		else if (data == "square")
		{
			addsfEntity(sfEntityName, new sf::RectangleShape(sf::Vector2f(100, 100)));
			//sfEntityIdMap[sfEntityName].shape = new sf::RectangleShape(sf::Vector2f(100, 100));
			//sfEntities.push_back(sfEntityPair(sfEntityName, &sfEntityIdMap[sfEntityName]));
		}
	}
	else if (name == "color")
	{
		if (data == "green")
			sfEntityIdMap[sfEntityName].shape->setFillColor(sf::Color::Green);
		else if (data == "red")
			sfEntityIdMap[sfEntityName].shape->setFillColor(sf::Color::Red);
		else if (data == "yellow")
			sfEntityIdMap[sfEntityName].shape->setFillColor(sf::Color::Yellow);
		else if (data == "blue")
			sfEntityIdMap[sfEntityName].shape->setFillColor(sf::Color::Blue);
		else if (data == "magenta")
			sfEntityIdMap[sfEntityName].shape->setFillColor(sf::Color::Magenta);
		else if (data == "black")
			sfEntityIdMap[sfEntityName].shape->setFillColor(sf::Color::Black);
		else if (data == "white")
			sfEntityIdMap[sfEntityName].shape->setFillColor(sf::Color::White);
		else if (data == "cyan")
			sfEntityIdMap[sfEntityName].shape->setFillColor(sf::Color::Cyan);
	}
	else if (name == "outlinethickness")
	{
		sfEntityIdMap[sfEntityName].shape->setOutlineThickness(atof(data.c_str()));
	}
}
