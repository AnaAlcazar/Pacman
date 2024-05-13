#include "Pacman.hpp"
#include "Renderer.hpp"
#include <math.h>
#include <iostream>
#include "ScreenManager.hpp"

Pacman::Pacman() : Entity(Player, { 13.5*8+4,26*8+4}, { -1, 0 }, 0.8f)
{
	pelletEffect = 0;
	pelletMultiplier = 0;

	Animation pUp={0,4};
	pUp.sprites.push_back(0);
	pUp.sprites.push_back(15);
	pUp.sprites.push_back(14);
	pUp.sprites.push_back(15);
	Animation pLeft = { 0,4 };
	pLeft.sprites.push_back(0);
	pLeft.sprites.push_back(17);
	pLeft.sprites.push_back(16);
	pLeft.sprites.push_back(17);
	Animation pDown = { 0,4 };
	pDown.sprites.push_back(0);
	pDown.sprites.push_back(19);
	pDown.sprites.push_back(18);
	pDown.sprites.push_back(19);
	Animation pRight = { 0,4 };
	pRight.sprites.push_back(0);
	pRight.sprites.push_back(21);
	pRight.sprites.push_back(20);
	pRight.sprites.push_back(21);
	Animation pDie = { 0,12 };
	pDie.sprites.push_back(0);
	pDie.sprites.push_back(1);
	pDie.sprites.push_back(2);
	pDie.sprites.push_back(3);
	pDie.sprites.push_back(4);
	pDie.sprites.push_back(5);
	pDie.sprites.push_back(6);
	pDie.sprites.push_back(7);
	pDie.sprites.push_back(8);
	pDie.sprites.push_back(9);
	pDie.sprites.push_back(10);
	pDie.sprites.push_back(11);
	anim.animations.push_back(pUp);
	anim.animations.push_back(pLeft);
	anim.animations.push_back(pDown);
	anim.animations.push_back(pRight);
	anim.animations.push_back(pDie);
}

float Pacman::GetPelletEffect()
{
	return pelletEffect;
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
	Entity::Move();

	cout << pelletEffect << endl;
}

void Pacman::Render()
{
	if (direction.y == -1)anim.Animate(position, 0, 0.1f, true);
	else if (direction.x == -1)anim.Animate(position, 1, 0.1f, true);
	else if (direction.y == 1)anim.Animate(position, 2, 0.1f, true);
	else if (direction.x == 1)anim.Animate(position, 3, 0.1f, true);
	DrawCircle(position.x, position.y, 2, RED);
	DrawCircle(GetTileOfEntity().x*8, GetTileOfEntity().y*8, 2, GREEN);
}

void Pacman::Kill()
{
}

void Pacman::Die()
{
}

void Pacman::EatPellet()
{
	pelletEffect = 50;
}

void Pacman::SetTargetTile(Vector2 tile)
{
}

