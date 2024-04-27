#include "EntityManager.hpp"

Entity::Entity(const Type t, const Vector2 pos, const Vector2 dir, const float sp)
{
	type = t;
	position = pos;
	direction = dir;
	nextDirection = dir;
	speed = sp;
}

Entity::~Entity()
{
}

Vector2 Entity::GetPosition()
{
	return position;
}

Vector2 Entity::GetDirection()
{
	return nextDirection;
}

Vector2 Entity::GetTileOfEntity()
{
	return { (float) (int)(position.x + 4 + direction.x == -1 ? -1 : 0) / 8, (float) (int)(position.y + 4 + direction.y == -1 ? -1 : 0) / 8 };
}

bool Entity::EntityIsCenteredInTile()
{
	if (position.x == GetTileOfEntity().x && position.y == GetTileOfEntity().y)return true;
	return false;
}
