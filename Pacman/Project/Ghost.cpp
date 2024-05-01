#include "Ghost.hpp"
#include "Renderer.hpp"
#include <iostream>
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
int Ghost::AvaiableDirections()
{
	int count;
	for (int i = 0; i < 4; i++)
	{
		ScreenManager::Instance().IsTangible({ GetTileOfEntity().x + IntToDirection(i).x, GetTileOfEntity().y + IntToDirection(i).y }) ? count++ : count;
	}
	
	return count;
}
Ghost::Ghost() : Entity(Enemy, { 13.5 * 8 + 4,14 * 8 + 4 }, { -1,0 }, 0.8f)
{
	ghostModeTimer = 7;
	modeRound = 0;
	targetTile = { 0,0 };
	ghostMode = Scatter;
	alive = true;
}

void Ghost::Input()
{
}

void Ghost::Logic()
{
	if(AvaiableDirections() > 2)
	else
	Move();
}

void Ghost::Render()
{
	Renderer::Instance().DrawSprite(0, { 0,2 }, position, WHITE);
}


Ghost::~Ghost()
{

}
