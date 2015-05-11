#pragma once
#include <SFML\Graphics.hpp>
#include "LevelManager.h"
#include "EntityManager.h"
#include "../display/DisplayGrid.h"
#include "../load/LoadFile.h"

class ScreenManager : public sf::RenderTexture, public LoadFile
{
	struct sfEntity
	{
		sf::Shape* shape;
		sf::Text text;
		bool visible = true;
		//sf::Sprite sprite;
	};
	typedef std::map<std::string, sfEntity> sfEntityMap;
	typedef std::pair<std::string, sfEntity*> sfEntityPair;
	typedef std::vector<sfEntityPair> sfEntityVec;
	sfEntityMap sfEntityIdMap;
	sfEntityVec sfEntities;
	std::string sfEntityName;
	sf::Font font;
	sf::View gridDisplay, controlDisplay;
	Position convertPosition(Position);
public:
	~ScreenManager();
	EntityManager* entityManager;
	LevelManager* levelManager;
	DisplayGrid grid;
	sf::RectangleShape pauseButton, inventoryBox;
	sf::Text pauseText;
	void init();
	void eventUpdate(sf::Event& event);
	void update();
	void render();
	sf::Shape& getsfEntity(std::string name);
	void addsfEntity(std::string name, sf::Shape* sfEntity);
	void store(std::string, std::string);
};

