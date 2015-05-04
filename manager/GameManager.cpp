#include "GameManager.h"
#include "LevelManager.h"
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
	float tempx = pos.x / (Config::gridDisplaySize / obs.getWidth());
	float tempy = pos.y / (Config::gridDisplaySize / obs.getHeight());
	return Position(std::round(tempx), std::round(tempy));
}

void GameManager::init()
{
	behaviorTree.loadFile("res/behaviortree.txt");
	//behaviorTree.printTree();
	behaviorTree.init();
}

void GameManager::eventUpdate(sf::Event& event)
{

}

void GameManager::update()
{
	behaviorTree.update();
}