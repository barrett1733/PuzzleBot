#pragma once
#include "LevelManager.h"
#include "EntityManager.h"
#include "ScreenManager.h"
#include "../pathfinding/pathfinding.h"
#include "../config/Config.h"
#include <SFML\Window.hpp>

class GameManager
{
	EntityManager entityManager;
	Position convPos(Position pos);
	Position start, nextPos;
	Pathfinding* test;
	Path path;

public:
	~GameManager(){ delete test; test = NULL; }
	ScreenManager* world;
	LevelManager levelManager;
	void init();
	void update();
	void eventUpdate(sf::Event&);
};

