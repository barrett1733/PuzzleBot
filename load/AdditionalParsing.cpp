#include "AdditionalParsing.h"

Position AdditionalParsing::parseCoords(std::string coord)
{
	char delimiter = ',';
	int lineDelim = coord.find(delimiter);
	std::string x, y;

	x = coord.substr(0, lineDelim);
	y = coord.substr(lineDelim + 1, coord.size());

	return Position(atoi(x.c_str()), atoi(y.c_str()));

}
