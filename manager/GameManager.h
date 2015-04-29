#pragma once
#include "LevelManager.h"
#include "EntityManager.h"
#include "ScreenManager.h"
#include "../pathfinding/pathfinding.h"
#include "../config/Config.h"
#include <SFML\Window.hpp>

class GameManager
{
	Position convGridPos(Position pos);
	Position convScreenPos(Position pos);
	Position start, nextPos;
	Pathfinding* test;
	Path path;
	bool key = false;

public:
	~GameManager(){ delete test; test = NULL; }
	EntityManager* entityManager;
	LevelManager* levelManager;
	void init();
	void update();
	void eventUpdate(sf::Event&);
};

