#pragma once
#include <map>
#include "SFML\Graphics\Color.hpp"

typedef std::map<std::string, sf::Color> ColorMap;
static ColorMap colorConfig;

typedef std::map<std::string, std::string> StringMap;
static StringMap stringConfig;