#pragma once
#include "LevelManager.h"
#include "EntityManager.h"
#include "ScreenManager.h"
#include "../config/Config.h"
#include <SFML\Window.hpp>
#include "../behavior/BehaviorTree.h"

class GameManager
{
	Position convGridPos(Position pos);
	Position convScreenPos(Position pos);
	Position start, nextPos;
	BehaviorTree behaviorTree;

public:
	EntityManager* entityManager;
	LevelManager* levelManager;
	void init();
	void update();
	void eventUpdate(sf::Event&);
};

