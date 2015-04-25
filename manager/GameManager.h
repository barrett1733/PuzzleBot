#pragma once
#include "LevelManager.h"
#include "EntityManager.h"

class GameManager
{
	LevelManager levelMng;
	EntityManager entityMng;
public:
	void init();
	void update();
};

