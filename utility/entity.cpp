#include "entity.h"
#include "distance.h"

Entity::Entity(Position position, float speed) :
	position(position),
	speed(speed),
	barrier(false),
	visible(true)
{ }

Entity::Entity(const Entity & entity) :
	position(entity.position),
	speed(entity.speed),
	barrier(entity.barrier),
	visible(entity.visible)
{ }

Entity::Entity() :
	position(0, 0),
	speed(0.0),
	barrier(false),
	visible(true)
{ }

Entity& Entity::operator= (const Entity& entity)
{
	position = entity.position;
	return *this;
}

void Entity::moveTowards(Position newPos, float speed)
{
	double dist = EuclideanDistance(position, newPos);

	float dx = newPos.x - position.x;
	float dy = newPos.y - position.y;

	dist > 0 ? dx /= dist : dx;
	dist > 0 ? dy /= dist : dy;

	dx *= speed;
	dy *= speed;

	position.x += dx;
	position.y += dy;
}

void Entity::moveTowards(Direction dir, float speed)
{
	moveTowards(position.getNeighbor(dir), speed);
}

void Entity::moveTowards(Direction dir)
{
	moveTowards(position.getNeighbor(dir), speed);
}

void Entity::moveTowards(Position pos)
{
	moveTowards(pos, speed);
}
