#pragma once
#include <SFML\Graphics.hpp>
#include "LevelManager.h"
#include "EntityManager.h"
#include "../display/DisplayGrid.h"
#include "../load/LoadFile.h"

struct sfEntity
{
	sf::Shape* shape;
	bool grid = true;
};

class ScreenManager : public sf::RenderTexture, public LoadFile
{
	typedef std::map<std::string, sf::Shape*> sfEntityMap;
	typedef std::map<std::string, sf::Shape*>::iterator sfEntityMapIter;
	sfEntityMap sfEntities;
	std::string sfEntityName;
	sf::View gridDisplay, controlDisplay;
	Position convertPosition(Position);
public:
	EntityManager* entityManager;
	LevelManager* levelManager;
	DisplayGrid grid;
	sf::RectangleShape button;
	void init();
	void eventUpdate(sf::Event& event);
	void update();
	void render();
	sf::Shape& getsfEntity(std::string name);
	void addsfEntity(std::string name, sf::Shape* sfEntity);
	void store(std::string, std::string);
};

