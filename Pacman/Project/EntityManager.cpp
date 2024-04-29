#include "EntityManager.hpp"
#include "Pacman.hpp"
#include "Ghost.hpp"
#include "ScreenManager.hpp"

void Entity::Move()
{
	if(ScreenManager::Instance().IsTangible({position.x+direction.x}))
	position.x += direction.x * speed;
	position.y += direction.y * speed;
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
	int x = position.x / 8;
	int y = position.y / 8;
	return {(float) x, (float) y};
}

bool Entity::EntityIsCenteredInTile()
{
	if (position.x == GetTileOfEntity().x && position.y == GetTileOfEntity().y)return true;
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

EntityManager::~EntityManager()
{
	for (int i = 0; i < entityList.size(); i++)
	{
		delete entityList[i];
	}
	entityList.clear();
}


