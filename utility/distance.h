#pragma once
#include "position.h"
#include <algorithm>

float ManhattanDistance(Position node, Position goal);
float DiagonalDistance(Position node, Position goal);
float EuclideanDistance(Position node, Position goal);
