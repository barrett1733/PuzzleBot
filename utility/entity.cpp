#include "entity.h"
#include "distance.h"

Entity::Entity(Position position, float speed) :
	position(position),
	speed(speed)
{ }

Entity::Entity(const Entity & entity) :
	position(entity.position),
	speed(entity.speed)
{ }

Entity::Entity() :
	position(0,0),
	speed(0.0)
{ }

Entity& Entity::operator= (const Entity& entity)
{
	position = entity.position;
	return *this;
}

void Entity::moveTowards(Position newPos)
{
	double dist = EuclideanDistance(position, newPos);

	float dx = newPos.x - position.x;
	float dy = newPos.y - position.y;

	dist > 0 ? dx /= dist : dx;
	dist > 0 ? dy /= dist : dy;

	dx *= speed;
	dy *= speed;

	position = Position(position.x + dx, position.y + dy);
}