//  Entity Class Implementation
//  Mobile Entity Class Implementation
//

#include "entity.h"

Entity::Entity(Position position) :
	position(position)
{ }

Entity::Entity(const Entity & entity) :
	position(entity.position)
{ }

Entity::Entity() :
	position()
{ }

Entity& Entity::operator= (const Entity& entity)
{
	position = entity.position;
	return *this;
}

Position Entity::getPosition() const
{
	return this->position;
}

void Entity::setPosition(Position position)
{
	this->position = position;
}
