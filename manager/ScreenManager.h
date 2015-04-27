#pragma once
#include <SFML\Graphics.hpp>
#include "LevelManager.h"
#include "../display/DisplayGrid.h"

class ScreenManager : public sf::RenderTexture
{
	sf::View gridDisplay, controlDisplay;
	std::vector<sf::Drawable*> gridObjects, controlPanelObjects;
public:
	DisplayGrid grid;
	sf::CircleShape robot;
	sf::RectangleShape button;
	LevelManager* levelManager;
	void init();
	void eventUpdate(sf::Event& event);
	void update();
	void render();
};

