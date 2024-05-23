#include "Pacman.hpp"
#include "Renderer.hpp"
#include "GameStateMachine.hpp"
#include "Ghost.hpp"
#include <math.h>
#include <iostream>
#include "ScreenManager.hpp"

Pacman::Pacman() : Entity(Player, {13.5*8+4,26*8+4}, { -1, 0 }, 0.8f, { 13.5f,26})
{
	pelletEffect = 0;
	pelletMultiplier = 0;
	scoreTimer = 0;
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
	Animation pDie = { 0,13 };
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
	pDie.sprites.push_back(-1);
	anim.animations.push_back(pUp);
	anim.animations.push_back(pLeft);
	anim.animations.push_back(pDown);
	anim.animations.push_back(pRight);
	anim.animations.push_back(pDie);
	Revive();
}

float Pacman::GetPelletEffect()
{
	return pelletEffect;
}

bool Pacman::HasPelletEffect()
{
	return pelletEffect > 0? true:false;
}

int Pacman::GetPelletMultiplier()
{
	return pelletMultiplier;
}

void Pacman::ResetPelletEffect()
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
	Entity::Move();

	if (pelletEffect > 0)pelletEffect -= GetFrameTime();
	else
		ResetPelletEffect();
	if (scoreTimer > 0 && GameStateMachine::Instance().game->GetStage() == 4)
	{
		scoreTimer -= GetFrameTime();
	}
	else if(GameStateMachine::Instance().game->GetStage() == 4)
		GameStateMachine::Instance().game->SetStage(1);
}

void Pacman::Render()
{
	if (GameStateMachine::Instance().game->GetStage() == 0)
	{
		Renderer::Instance().DrawSprite(0,{3,1}, position, WHITE);
	}
	if (GameStateMachine::Instance().game->GetStage() == 1)
	{
		if (direction.y == -1)anim.Animate(position, 0, 0.1f, true);
		else if (direction.x == -1)anim.Animate(position, 1, 0.1f, true);
		else if (direction.y == 1)anim.Animate(position, 2, 0.1f, true);
		else if (direction.x == 1)anim.Animate(position, 3, 0.1f, true);
	}
	else if (GameStateMachine::Instance().game->GetStage() == 3)
	{
		anim.Animate(position, 4, 0.2f, false);
	}
	else if (GameStateMachine::Instance().game->GetStage() == 4)
	{
		switch (pelletMultiplier - 1)
		{
		case 1:
			Renderer::Instance().DrawSprite(0, { 10,1 }, { position.x, position.y}, WHITE);
			break;
		case 2:
			Renderer::Instance().DrawSprite(0, { 12,0 }, { position.x, position.y}, WHITE);
			break;
		case 3:
			Renderer::Instance().DrawSprite(0, { 13,1 }, { position.x, position.y}, WHITE);
			break;
		case 4:
			Renderer::Instance().DrawSprite(0, { 13,3 }, { position.x, position.y}, WHITE);
			Renderer::Instance().DrawSprite(0, { 12,3 }, { position.x-(8*SCALE_FACTOR), position.y }, WHITE);
			break;
		default:
			break;
		}
	}
}

void Pacman::Kill()
{
	GameStateMachine::Instance().game->SetStage(4);
	pelletMultiplier++;
	GameStateMachine::Instance().game->AddScore(100 * pow(2, pelletMultiplier));
}

void Pacman::Revive()
{
	alive = true;
}

bool Pacman::IsAlive()
{
	return alive;
}

void Pacman::Die()
{
	alive = false;
	GameStateMachine::Instance().game->SetStage(3);
}

void Pacman::EatPellet()
{
	pelletEffect = 10;
	pelletMultiplier = 1;
	for (int i = 1; i < 5; i++)
	{
		dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->ChangeMode(Ghost::Frightened);
		dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->stage = 4;
	}
}

void Pacman::SetTargetTile(Vector2 tile)
{
}

