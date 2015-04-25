#pragma once
#include "../pathfinding/obstruction-map.h"
#include "../graphics/GraphicsGrid.h"

class DisplayGrid : public sf::RectangleShape
{
	typedef std::map<std::string, sf::Color> ColorIdMap;
	static ColorIdMap GridColors; // pair of id and color - TODO change this

	ObstructionMap* obsMap;

	sf::Color getTileColor(ObstructionType) const;
	void loadColors(); // Testing only

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	DisplayGrid();
	DisplayGrid(ObstructionMap* obsMap);
	~DisplayGrid();

	void setGrid(ObstructionMap* obsMap);
};

