#include <SFML/Graphics.hpp>
#include "utility\timer.h"
#include <iomanip>
#include "manager\ScreenManager.h"
#include "manager\GameManager.h"
#include "behavior\BehaviorTree.h"
#include "config\Config.h"


int main()
{
	/*
	BehaviorTree testtree;
	testtree.loadFile("res/behaviortest.txt");
	testtree.printTree();
	std::cin.get();
	*/
	ScreenManager world;
	world.create(SCREEN_WIDTH, SCREEN_HEIGHT);
	world.init();

	GameManager game;
	game.init();
	game.world = &world;

	world.levelManager = &game.levelManager;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	
	steady_clock::time_point prev = steady_clock::now();
	steady_clock::duration lag = steady_clock::duration::zero();

	while (window.isOpen())
	{
		steady_clock::time_point cur = steady_clock::now();
		steady_clock::duration elapsed = cur - prev;
		prev = cur;
		lag += elapsed;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			game.eventUpdate(event);
		}

		steady_clock::duration MS_PER_UPDATE = milliseconds(5);
		while (lag >= MS_PER_UPDATE)
		{
			game.update();
			lag -= MS_PER_UPDATE;
		}

		
		window.clear();
		world.render();
		world.display();
		sf::Sprite sprite(world.getTexture());
		window.draw(sprite);
		window.display();
	}

	return 0;
}
