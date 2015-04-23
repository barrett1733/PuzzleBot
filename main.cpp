#include <SFML/Graphics.hpp>
#include "Display/DisplayGrid.h"
#include "pathfinding/pathfinding.h"
#include "utility/timer.h"
#include "utility/entity.h"
#include <iomanip>

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

Position convPos(Position pos, DisplayGrid &grid, ObstructionMap &obs)
{
	return Position(pos.getX() * (grid.getSize().x / obs.getWidth()) + grid.getPosition().x,
		pos.getY() * (grid.getSize().y / obs.getHeight()) + grid.getPosition().y);
}

int main()
{

	sf::View gridDisplay, controlDisplay;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	ObstructionMap obs = testGrid();
	DisplayGrid grid(&obs);

	gridDisplay = window.getDefaultView();
	
	int windowX = window.getSize().x;
	int windowY = window.getSize().y;
	const int controlPanelWidth = 200;

	sf::FloatRect controlPanelRect(windowX - controlPanelWidth, 0, controlPanelWidth, windowY);
	float controlPanelSize = (float) controlPanelWidth / windowX;

	controlDisplay.setViewport(sf::FloatRect(1 - controlPanelSize, 0, controlPanelSize, 1));
	controlDisplay.reset(controlPanelRect);

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
	button.setPosition(controlPanelRect.left + 10, controlPanelRect.top + 10);
	button.setOutlineColor(sf::Color::Black);
	button.setSize(sf::Vector2f(100, 100));

	sf::Font font;
	if (!font.loadFromFile("res/arial.ttf"))
	{
		std::cerr << "Font file not found..." << std::endl;
	}

	sf::Text robotCurPos, robotNextPos;
	robotCurPos.setPosition(sf::Vector2f(controlPanelRect.left + 10, controlPanelRect.top + 130));
	robotNextPos.setPosition(sf::Vector2f(controlPanelRect.left + 10, controlPanelRect.top + 150));
	robotCurPos.setColor(sf::Color::White);
	robotNextPos.setColor(sf::Color::White);
	robotCurPos.setFont(font);
	robotNextPos.setFont(font);
	robotCurPos.setCharacterSize(12);
	robotNextPos.setCharacterSize(12);

	Entity robot(convPos(start, grid, obs));
	Position nextPos(convPos(path[0], grid, obs));

	sf::CircleShape robotGraphics;
	robotGraphics.setFillColor(sf::Color::Green);
	robotGraphics.setPosition(robot.position.x, robot.position.y);
	robotGraphics.setRadius(grid.getSize().y / obs.getHeight() / 2);

	int movecounter = 1;
	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path[i] << " -> " << convPos(path[i], grid, obs) << std::endl;
	}

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
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (button.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					button.setFillColor(sf::Color::Green);
					std::cout << "pressed" << std::endl;
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (button.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					button.setFillColor(sf::Color::Red);
					std::cout << "released" << std::endl;
				}
			}
		}

		steady_clock::duration MS_PER_UPDATE = milliseconds(5);
		while (lag >= MS_PER_UPDATE)
		{
			if (EuclideanDistance(robot.position, nextPos) <= robot.speed && movecounter + 1 < path.size())
			{
				std::cout << movecounter << std::endl;
				movecounter++;
				nextPos = convPos(path[movecounter], grid, obs);
			}
			//update();
			lag -= MS_PER_UPDATE;
		}

		if (movecounter < path.size())
		{
			robot.moveTowards(nextPos);
			robotGraphics.setPosition(robot.position.x, robot.position.y);
		}

		robotCurPos.setString(sf::String("(" + std::to_string(robot.position.x) + ", " + std::to_string(robot.position.y) + ")"));
		robotNextPos.setString(sf::String("(" + std::to_string(nextPos.x) + ", " + std::to_string(nextPos.y) + ")"));
		
		window.clear();
		window.setView(gridDisplay);
		window.draw(grid);
		window.draw(robotGraphics);
		window.setView(controlDisplay);
		window.draw(button);
		window.draw(robotCurPos);
		window.draw(robotNextPos);
		window.display();
	}

	return 0;
}