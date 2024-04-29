#include "Ghost.hpp"
#include "Renderer.hpp"
#include <iostream>
Ghost::Ghost() : Entity(Enemy, { 13.5 * 8 + 4,14 * 8 + 4 }, { -1,0 }, 0.8f)
{
	ghostModeTimer = 7;
	modeRound = 0;
	targetTile = { 0,0 };
	ghostMode = Scatter;
	alive = true;
	std::cout << "Ghost created";
}

void Ghost::Input()
{
}

void Ghost::Logic()
{
	Move();
	DrawRectangleLinesEx({ GetTileOfEntity().x * 8, GetTileOfEntity().y * 8, 8, 8 }, 1, RED);
}

void Ghost::Render()
{
	Renderer::Instance().DrawSprite(0, { 0,2 }, position, WHITE);
}


Ghost::~Ghost()
{

}
