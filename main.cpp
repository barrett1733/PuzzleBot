#include <SFML/Graphics.hpp>
#include "Display/DisplayGrid.h"
#include "pathfinding/pathfinding.h"
#include "utility\timer.h"

ObstructionMap testGrid()
{
	int mapSizeX = 10;
	int mapSizeY = 10;

	Position::max_x = mapSizeX;
	Position::max_y = mapSizeY;

	Position start = Position(0, 4);
	Position goal = Position(9, 4);

	ObstructionMap testmap(mapSizeX, mapSizeY);
	std::vector<std::pair<int, int>> obs = {
			{ 2, 2 }, { 2, 3 }, { 2, 5 }, { 2, 6 },
			{ 3, 1 }, { 3, 2 }, { 3, 6 }, { 3, 7 },
			{ 4, 1 }, { 4, 7 },
			{ 5, 1 }, { 5, 2 }, { 5, 6 }, { 5, 7 },
			{ 6, 2 }, { 6, 3 }, { 6, 4 }, { 6, 5 }, { 6, 6 }
	};
	for (int i = 0; i < obs.size(); i++)
		testmap.at(Position(obs[i].first, obs[i].second)) = OT_OBSTRUCTED;
	return testmap;
}

int main()
{

	sf::View gridDisplay, controlDisplay;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	ObstructionMap obs = testGrid();
	DisplayGrid grid(&obs);

	gridDisplay = window.getDefaultView();
	controlDisplay.setViewport(sf::FloatRect(0.5f, 0, 0.5f, 0.5f));
	std::cout << controlDisplay.getCenter().x << " " << controlDisplay.getCenter().y << std::endl;

	const int controlPanelWidth = 200;

	float controlPanelSize = controlPanelWidth / gridDisplay.getSize().x;
	float controlPanelCenter = gridDisplay.getSize().x - (gridDisplay.getSize().x - controlPanelWidth);
	std::cout << controlPanelSize << std::endl;
	controlDisplay.setViewport(sf::FloatRect(1 - controlPanelSize, 0, controlPanelSize, 1));
	controlDisplay.setSize(controlPanelWidth, gridDisplay.getSize().y);
	controlDisplay.setCenter(controlPanelWidth / 2, gridDisplay.getSize().y / 2);

	grid.setPosition(sf::Vector2f(0, 0));
	grid.setSize(sf::Vector2f(600, 600));
	grid.setOutlineThickness(1);
	grid.setOutlineColor(sf::Color::Black);

	Position start = Position(0, 4);
	Position goal = Position(9, 4);

	Pathfinding test(10, 10);
	Path path = test.findPath(start, goal, &obs);

	sf::RectangleShape button;
	button.setFillColor(sf::Color::Red);
	button.setPosition(10, 10);
	button.setOutlineColor(sf::Color::Black);
	button.setSize(sf::Vector2f(100, 100));

	sf::CircleShape robot;
	Position robotPos(start.getX() * (grid.getSize().x / obs.getWidth()) + grid.getPosition().x,
		start.getY() * (grid.getSize().y / obs.getHeight()) + grid.getPosition().y);
	Position stop(500, 500);

	robot.setFillColor(sf::Color::Green);
	robot.setPosition(robotPos.getX(), robotPos.getY());
	//robot.setPosition(10, 10);
	robot.setRadius(20);

	int xcounter = stop.getX() - robotPos.getX();
	int ycounter = stop.getY() - robotPos.getY();

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
		}

		steady_clock::duration MS_PER_UPDATE = milliseconds(5);
		while (lag >= MS_PER_UPDATE)
		{
			if (xcounter > 0)
			{
				robot.setPosition(robot.getPosition().x + 0.1, robot.getPosition().y);
				xcounter -= 0.1;
			}
			if (ycounter > 0)
			{
				robot.setPosition(robot.getPosition().x, robot.getPosition().y + 0.1);
				ycounter -= 0.1;
			}

			//update();
			lag -= MS_PER_UPDATE;
		}

		
		window.clear();
		window.setView(gridDisplay);
		window.draw(grid);
		window.draw(robot);
		window.setView(controlDisplay);
		window.draw(button);
		window.display();
	}

	return 0;
}