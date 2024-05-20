#include "EntityManager.hpp"
#include "ScreenManager.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "Blinky.hpp"
#include "Pinky.hpp"
#include "Inky.hpp"
#include "Clyde.hpp"
#include "Globals.hpp"
#include <math.h>
#include <iostream>

void Entity::TrySetDirection(Vector2 dir)
{
	if (ScreenManager::Instance().OnTunnel(GetTileOfEntity()) && type == Enemy)return;
	if (dir.x == nextDirection.x && dir.y == nextDirection.y) return;
	Vector2 targetTile = { GetTileOfEntity().x + dir.x*2, GetTileOfEntity().y + dir.y*2 };
	if (!ScreenManager::Instance().IsTangible(targetTile))return;
	if (abs(position.x - GetTileOfEntity().x * 8) > 4 && abs(position.y - GetTileOfEntity().y * 8) > 4)return;
	nextDirection = dir;
	position.x = GetTileOfEntity().x * 8 + 4;
	position.y = GetTileOfEntity().y * 8 + 4;
}
void Entity::ForceDirection(Vector2 dir)
{
	direction = dir;
}
void Entity::ResetPosition()
{
	float x = StartTile.x * 8 +4;
	float y = StartTile.y * 8 +4;
	position = { x,y };
}
void Entity::Move()
{
	if (EntityIsCenteredInTile(GetTileOfEntity()))
	{
		direction = nextDirection;
	}
	bool NextTileTangible = ScreenManager::Instance().IsTangible({ GetTileOfEntity().x + direction.x, GetTileOfEntity().y + direction.y });
	if (ScreenManager::Instance().OnTunnel(GetTileOfEntity()))
	{
		position.x += direction.x * speed;
		position.y += direction.y * speed;
	}
	else if (!NextTileTangible && EntityIsCenteredInTile(GetTileOfEntity()))
	{}
	else
	{
		position.x += direction.x * speed;
		position.y += direction.y * speed;
	}
	if (position.x < -4 && direction.x == -1)position.x = 224;
	else if (position.x > 228 && direction.x == 1)position.x = -8;
}

Entity::Entity(const EntityType t, const Vector2 pos, const Vector2 dir, const float sp, Vector2 st)
{
	type = t;
	direction = dir;
	nextDirection = dir;
	speed = sp;
	StartTile = st;
	alive = true;
	ResetPosition();
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
	if (direction.x == -1 && (abs(position.x - tile.x * 8) < 4) && (abs(position.y - tile.y * 8) <= 4))return true;
	else if (direction.x == 1 && (abs(position.x - tile.x * 8) >= 4) && (abs(position.y - tile.y * 8) <= 4))return true;
	else if (direction.y == -1 && (abs(position.y - tile.y * 8) < 4) && (abs(position.x - tile.x * 8) <= 4))return true;
	else if (direction.y == 1 && (abs(position.y - tile.y * 8) >= 4) && (abs(position.x - tile.x * 8) <= 4))return true;
	return false;
}

bool Entity::IsAlive()
{
	return alive;
}

EntityManager::EntityManager()
{
	entityList.push_back(new Pacman());
	entityList.push_back(new Blinky());
	entityList.push_back(new Pinky());
	entityList.push_back(new Inky());
	entityList.push_back(new Clyde());
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

void EntityManager::ResetAllPositions()
{
	for (int i = 0; i < 5; i++)
	{
		entityList[i]->ResetPosition();
	}
}

void EntityManager::ResetEntities()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		delete entityList[i];
	}
	entityList.clear();
	entityList.push_back(new Pacman());
	entityList.push_back(new Blinky());
	entityList.push_back(new Pinky());
	entityList.push_back(new Inky());
	entityList.push_back(new Clyde());
}

EntityManager::~EntityManager()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		delete entityList[i];
	}
	entityList.clear();
}


