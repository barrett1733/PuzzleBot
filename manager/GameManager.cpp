#include "GameManager.h"
#include "LevelManager.h"
#include "../pathfinding/pathfinding.h"
#include <SFML\Graphics.hpp>

Position GameManager::convPos(Position pos)
{
	ObstructionMap obs = *levelManager.getLevel(0);
	/*
	DisplayGrid grid = world->grid;
	ObstructionMap obs = *levelManager.getLevel(0);
	return Position(pos.getX() * (grid.getSize().x / obs.getWidth()) + grid.getPosition().x,
		pos.getY() * (grid.getSize().y / obs.getHeight()) + grid.getPosition().y);
		*/
	return Position(pos.getX() * (gridDisplaySize / obs.getWidth()), pos.getY() * (gridDisplaySize / obs.getHeight()));
}

void GameManager::init()
{
	levelManager.loadLevels();
	start = Position(0, 4);
	entityManager.robot.position = Position(convPos(start));

	test = new Pathfinding(LEVELSIZE, LEVELSIZE);
}

void GameManager::eventUpdate(sf::Event& event)
{

}

void GameManager::update()
{
	Position goal = Position(9, 4);
	if (path.empty())
		path = test->findPath(start, goal, levelManager.getLevel(0));
	//for (int i = 0; i < path.size(); i++)
	//	std::cout << path[i] << " -> " << convPos(path[i]) << std::endl;
	//std::cout << *path.begin() << " -> " << convPos(*path.begin()) << " " << entityManager.robot.position << std::endl;
	if (EuclideanDistance(entityManager.robot.position, nextPos) <= entityManager.robot.speed)
	{
		path.erase(path.begin());
	}
	if (!path.empty())
	{
		nextPos = convPos(*path.begin());
		entityManager.robot.moveTowards(nextPos);
		world->robot.setPosition(entityManager.robot.position.x, entityManager.robot.position.y);
	}

}