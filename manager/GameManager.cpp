#include "GameManager.h"
#include "LevelManager.h"
#include "../pathfinding/pathfinding.h"
#include <SFML\Graphics.hpp>
#include <cmath>

Position GameManager::convGridPos(Position pos)
{
	GridBool obs = *levelManager->getLevel(0);
	return Position(pos.x * (Config::gridDisplaySize / obs.getWidth()), pos.y * (Config::gridDisplaySize / obs.getHeight()));
}

Position GameManager::convScreenPos(Position pos)
{
	GridBool obs = *levelManager->getLevel(0);
	return Position(std::round(pos.x / (Config::gridDisplaySize / obs.getWidth())), std::round(pos.y / (Config::gridDisplaySize / obs.getHeight())));
}

void GameManager::init()
{
	start = entityManager->getEntity("robot").position;

	behaviorTree.loadFile("res/behaviortree.txt");
	behaviorTree.printTree();

	test = new Pathfinding(Config::LEVELSIZE, Config::LEVELSIZE);
}

void GameManager::eventUpdate(sf::Event& event)
{

}

void GameManager::update()
{

	Position goal;
	if (!key)
	{
		goal = entityManager->getEntity("key").position;
		key = true;
	}
	else
	{
		goal = entityManager->getEntity("exit").position;
	}
	if (path.empty())
	{
		start = entityManager->getEntity("robot").position;
		start.round();
		path = test->findPath(start, goal, levelManager->getLevel(0));
	}
	if (EuclideanDistance(entityManager->getEntity("robot").position, nextPos) <= entityManager->getEntity("robot").speed)
	{
		path.erase(path.begin());
	}
	if (!path.empty())
	{
		nextPos = *path.begin();
		entityManager->getEntity("robot").targetPos = nextPos;
		entityManager->getEntity("robot").move();
	}
}