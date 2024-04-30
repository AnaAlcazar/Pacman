#include "Pacman.hpp"
#include "Renderer.hpp"
#include <math.h>
#include <iostream>
#include "ScreenManager.hpp"
void Pacman::TrySetDirection(Vector2 dir)
{
	if (dir.x == nextDirection.x && dir.y == nextDirection.y) return;
	Vector2 targetTile = {GetTileOfEntity().x + dir.x, GetTileOfEntity().y + dir.y };
	DrawRectangleLinesEx({ targetTile.x*8, targetTile.y*8, 8,8 }, 1, RED);
	if (!ScreenManager::Instance().IsTangible(targetTile))return;
	std::cout << abs(position.x - (GetTileOfEntity().x + direction.x) * 8) << " " << abs(position.y - ((GetTileOfEntity().y + direction.y) * 8) > 4) << std::endl;
	if (abs(position.x - GetTileOfEntity().x*8) > 4 && abs(position.y - GetTileOfEntity().y*8) > 4)return;
	nextDirection = dir;
	position.x = GetTileOfEntity().x * 8+4;
	position.y = GetTileOfEntity().y * 8+4;
}

Pacman::Pacman() : Entity(Player, { 13.5*8+4,26*8+4}, { -1, 0 }, 0.8f)
{
	points = 0;
	pelletEffect = 0;
	pelletMultiplier = 0;
}

void Pacman::Input()
{
	if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
	{
		TrySetDirection({ 0,-1 });
	}
	else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
	{
		TrySetDirection({ -1, 0 });
	}
	else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
	{
		TrySetDirection({ 0, 1 });
	}
	else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
	{
		TrySetDirection({ 1, 0 });
	}
}

void Pacman::Logic()
{
	Move();
	DrawRectangleLinesEx({ GetTileOfEntity().x * 8, GetTileOfEntity().y * 8, 8, 8 }, 1, YELLOW);
}

void Pacman::Render()
{
	Renderer::Instance().DrawSprite(0, {0,0}, GetPosition(), WHITE);
}

