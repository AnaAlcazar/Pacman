#include "Ghost.hpp"
#include "Pacman.hpp"
#include "Renderer.hpp"
#include <math.h>
Vector2 Ghost::IntToDirection(int index)
{
	switch (index)
	{
	case 0:
		return { 0,-1 };
	case 1:
		return { -1,0 };
	case 2:
		return { 0,1 };
	case 3:
		return { 1,0 };
	default:
		break;
	}
	return Vector2();
}
bool Ghost::ContraryDirections()
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (ScreenManager::Instance().IsTangible({ GetTileOfEntity().x + IntToDirection(i).x , GetTileOfEntity().y + IntToDirection(i).y }))
			count += i;
	}
	if (count % 2 == 0)return true;
	return false;
}
int Ghost::AvaiableDirections()
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		ScreenManager::Instance().IsTangible({ GetTileOfEntity().x + IntToDirection(i).x, GetTileOfEntity().y + IntToDirection(i).y }) ? count++ : count;
	}
	
	return count;
}
Vector2 Ghost::GetTargetTile()
{
	return targetTile;
}
void Ghost::DecideDirection(bool canTurnBack)
{
	Vector2 selectedDirection = { 0,0 };
	for (int i = 0; i < 4; i++)
	{
		if (!canTurnBack && (IntToDirection(i).x * -1 == direction.x && IntToDirection(i).y * -1 == direction.y))continue;
		else if (!ScreenManager::Instance().IsTangible({ GetTileOfEntity().x + IntToDirection(i).x , GetTileOfEntity().y + IntToDirection(i).y }))continue;
		else if ((GetTileOfEntity().x == 13 || GetTileOfEntity().x == 14) && GetTileOfEntity().y == 14 && i == 2)continue;
		else if (selectedDirection.x == 0 && selectedDirection.y == 0)
		{
			selectedDirection = IntToDirection(i);
			continue;
		}
		else if (hypot(GetTileOfEntity().x + IntToDirection(i).x - targetTile.x, GetTileOfEntity().y + IntToDirection(i).y - targetTile.y) < hypot(GetTileOfEntity().x + selectedDirection.x - targetTile.x, GetTileOfEntity().y + selectedDirection.y - targetTile.y))
			selectedDirection = IntToDirection(i);
	}
	TrySetDirection(selectedDirection);
	intersectionDecided = true;
}
Ghost::Ghost(Vector2 st, float t) : Entity(Enemy, { 13.5 * 8 + 4,8 * 8 + 4 }, { 0,-1 }, 0.8f, st)
{
	IsInBox = true;
	timerToStart = t;
	targetTile = { 0,0 };
	ghostMode = Scatter;
	alive = true;
	intersectionDecided = false;
	stage = 0;
}

void Ghost::Input()
{
}

void Ghost::Logic()
{
	Brain();

	if (ScreenManager::Instance().OnTunnel(GetTileOfEntity()))speed = 0.4f;
	else speed = 0.8f;
	if(!intersectionDecided)
		DecideDirection(false);
	if (AvaiableDirections() < 3 && ContraryDirections())
		intersectionDecided = false;
	Entity::Move();
	Kill();
}

void Ghost::Brain()
{
}

void Ghost::Render()
{}

void Ghost::SetTargetTile(Vector2 tile)
{
	targetTile = tile;
}

void Ghost::ChangeMode(Mode m)
{
	ghostMode = m;
	DecideDirection(true);
}

void Ghost::Kill()
{
	Vector2 pacmanTile = EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity();
	if (!(GetTileOfEntity().x == pacmanTile.x) || !(GetTileOfEntity().y == pacmanTile.y))return;
	else
	{
		if (ghostMode == Frightened && alive)
		{
			Die();
			EntityManager::Instance().GetEntityAt(0)->Kill();
		}
		else if(ghostMode != Frightened && alive)
			EntityManager::Instance().GetEntityAt(0)->Die();
	}
}

void Ghost::Die()
{
	alive = false;
	DecideDirection(true);
}

Ghost::~Ghost()
{}