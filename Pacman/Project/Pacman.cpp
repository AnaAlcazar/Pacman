#include "Pacman.hpp"
#include "Renderer.hpp"
#include <math.h>
#include <iostream>
#include "ScreenManager.hpp"

Pacman::Pacman() : Entity(Player, { 13.5*8+4,26*8+4}, { -1, 0 }, 0.8f)
{
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
}

void Pacman::Render()
{
	Renderer::Instance().DrawSprite(0, {0,0}, GetPosition(), WHITE);
}

