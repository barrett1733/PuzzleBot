#pragma once
#include <SFML\Graphics.hpp>
#include "LevelManager.h"
#include "../display/DisplayGrid.h"

class ScreenManager : public sf::RenderTexture
{
	sf::View gridDisplay, controlDisplay;
	LevelManager levels;
	DisplayGrid grid;
public:
	ScreenManager();
	~ScreenManager();
	void init();
	void update();
};

