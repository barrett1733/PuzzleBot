#include <SFML/Graphics.hpp>
#include "Display/DisplayGrid.h"

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
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	ObstructionMap obs = testGrid();
	DisplayGrid grid(&obs);
	
	grid.setPosition(sf::Vector2f(10, 10));
	grid.setSize(sf::Vector2f(500, 500));
	grid.setOutlineThickness(1);
	grid.setOutlineColor(sf::Color::Black);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(grid);
		window.display();
	}

	return 0;
}