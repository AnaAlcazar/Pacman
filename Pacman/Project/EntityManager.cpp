#include "EntityManager.hpp"
#include "ScreenManager.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include <math.h>

void Entity::TrySetDirection(Vector2 dir)
{
	if (dir.x == nextDirection.x && dir.y == nextDirection.y) return;
	Vector2 targetTile = { GetTileOfEntity().x + dir.x*2, GetTileOfEntity().y + dir.y*2 };
	if (!ScreenManager::Instance().IsTangible(targetTile))return;
	if (abs(position.x - GetTileOfEntity().x * 8) > 4 && abs(position.y - GetTileOfEntity().y * 8) > 4)return;
	nextDirection = dir;
	position.x = GetTileOfEntity().x * 8 + 4;
	position.y = GetTileOfEntity().y * 8 + 4;
}

void Entity::Move()
{
	if (EntityIsCenteredInTile(GetTileOfEntity()))
	{
		direction = nextDirection;
	}
	bool NextTileTangible = ScreenManager::Instance().IsTangible({ GetTileOfEntity().x + direction.x, GetTileOfEntity().y + direction.y });
	if (!NextTileTangible && EntityIsCenteredInTile(GetTileOfEntity()))
	{}
	else
	{
		position.x += direction.x * speed;
		position.y += direction.y * speed;
	}
}

Entity::Entity(const Type t, const Vector2 pos, const Vector2 dir, const float sp)
{
	type = t;
	position = pos;
	direction = dir;
	nextDirection = dir;
	speed = sp;
	alive = true;
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
	int x = (position.x-1) / 8;
	int y = (position.y-1) / 8;
	return {(float) x, (float) y};
}

bool Entity::EntityIsCenteredInTile(Vector2 tile)
{
	if (abs(position.x - tile.x * 8 -(4 * direction.x + 4)) <= 4 && abs(position.y - tile.y * 8) <= 4)return true;
	if (abs(position.x - tile.x * 8) <= 4 && abs(position.y - tile.y * 8 - (4 * direction.y + 4)) <= 4)return true;
	return false;
}

bool Entity::IsAlive()
{
	return alive;
}

EntityManager::EntityManager()
{
	entityList.push_back(new Pacman());
	entityList.push_back(new Ghost());
	entityList.push_back(new Ghost());
	entityList.push_back(new Ghost());
	entityList.push_back(new Ghost());
}

int EntityManager::entityListLength()
{
	return entityList.size();
}

Entity* EntityManager::GetEntityAt(int index)
{
	return entityList[index];
}

void EntityManager::Input()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		entityList[i]->Input();
	}
}

void EntityManager::Logic()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		entityList[i]->Logic();
	}
}

void EntityManager::Render()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		entityList[i]->Render();
	}
}

void EntityManager::SetTargetTile(Entity* entity, Vector2 tile)
{
	entity->SetTargetTile(tile);
}

EntityManager::~EntityManager()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		delete entityList[i];
	}
	entityList.clear();
}


