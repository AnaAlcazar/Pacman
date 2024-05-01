#include "Ghost.hpp"
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
void Ghost::DecideDirection(bool canTurnBack)
{
	Vector2 selectedDirection = { 0,0 };
	for (int i = 0; i < 4; i++)
	{
		if (!canTurnBack && (IntToDirection(i).x * -1 == direction.x && IntToDirection(i).y * -1 == direction.y))continue;
		else if (!ScreenManager::Instance().IsTangible({ GetTileOfEntity().x + IntToDirection(i).x , GetTileOfEntity().y + IntToDirection(i).y }))continue;
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
Ghost::Ghost() : Entity(Enemy, { 13.5 * 8 + 4,9 * 8 + 4 }, { -1,0 }, 0.8f)
{
	ghostModeTimer = 7;
	modeRound = 0;
	targetTile = { 0,0 };
	ghostMode = Scatter;
	alive = true;
	intersectionDecided = false;
}

void Ghost::Input()
{
}

void Ghost::Logic()
{
	if(!intersectionDecided)
		DecideDirection(false);
	if (AvaiableDirections() < 3 && ContraryDirections())
		intersectionDecided = false;
	Move();
}

void Ghost::Render()
{
	Renderer::Instance().DrawSprite(0, { 0,2 }, position, WHITE);
}

void Ghost::SetTargetTile(Vector2 tile)
{
	targetTile = tile;
}

Ghost::~Ghost()
{

}
