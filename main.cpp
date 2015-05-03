#include <SFML/Graphics.hpp>
#include "utility\timer.h"
#include <iomanip>
#include "manager\ScreenManager.h"
#include "manager\GameManager.h"
#include "manager\LevelManager.h"
#include "behavior\BehaviorTree.h"
#include "config\Config.h"


int main()
{
	LevelManager levels;
	levels.loadFile("res/levels.txt");
	EntityManager entities;
	entities.loadFile("res/entities.txt");
	
	ScreenManager screen;
	screen.levelManager = &levels;
	screen.entityManager = &entities;
	screen.create(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT);
	screen.init();
	screen.loadFile("res/screen graphics.txt");

	GameManager game;
	game.levelManager = &levels;
	game.entityManager = &entities;
	game.init();

	sf::RenderWindow window(sf::VideoMode(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT), "Puzzlebot");
	
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
			screen.eventUpdate(event);
		}

		steady_clock::duration MS_PER_UPDATE = milliseconds(5);
		while (lag >= MS_PER_UPDATE)
		{
			if (!Config::gamePause)
			{
				game.update();
				screen.update();
			}
			lag -= MS_PER_UPDATE;
		}

		
		window.clear();
		screen.render();
		screen.display();
		sf::Sprite sprite(screen.getTexture());
		window.draw(sprite);
		window.display();
	}

	return 0;
}
