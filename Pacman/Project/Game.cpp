#include "Game.hpp"
#include "Renderer.hpp"
#include <iostream>

Game::Game()
{
	lives = 3;
	score = 0;
	mode = 1;
}

void Game::Input()
{
	EntityManager::Instance().Input();
	if (IsKeyDown(KEY_LEFT))mode = 0;
	else if (IsKeyDown(KEY_RIGHT))mode = 1;
	else if (IsKeyDown(KEY_SPACE))ResetLayout();
}

void Game::Logic()
{
	if (mode == 0)
	{
		EntityManager::Instance().SetTargetTile(EntityManager::Instance().GetEntityAt(1), EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity());
		EntityManager::Instance().SetTargetTile(EntityManager::Instance().GetEntityAt(2), EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity());
		EntityManager::Instance().SetTargetTile(EntityManager::Instance().GetEntityAt(3), EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity());
		EntityManager::Instance().SetTargetTile(EntityManager::Instance().GetEntityAt(4), EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity());
	}
	else if(mode == 1)
	{
		EntityManager::Instance().SetTargetTile(EntityManager::Instance().GetEntityAt(1), {25, 0});
		EntityManager::Instance().SetTargetTile(EntityManager::Instance().GetEntityAt(2), {2, 0});
		EntityManager::Instance().SetTargetTile(EntityManager::Instance().GetEntityAt(3), {27, 35});
		EntityManager::Instance().SetTargetTile(EntityManager::Instance().GetEntityAt(4), {0, 35});
	}
	EatDot(); 
	EntityManager::Instance().Logic();
}

void Game::Render()
{
	RenderPoints();
	EntityManager::Instance().Render();
}

void Game::ResetLayout()
{
	for (int y = 0; y < 36; y++)
	{
		for (int x = 0; x < 28; x++)
		{
			if (pointsLayout[y][x] == -1)continue;
			if (pointsLayout[y][x] < 0)
				pointsLayout[y][x] *= -1;
		}
	}
}

void Game::RenderPoints()
{
	for (int y = 0; y < 36; y++)
	{
		for (int x = 0; x < 28; x++)
		{
			if (pointsLayout[y][x] < 0)continue;
			Renderer::Instance().DrawSprite(1, Renderer::Instance().SpriteIndexToPosition(1, pointsLayout[y][x] - 1), {(float) (x * 8 + 4),(float)(y * 8 + 4)}, 4);
		}
	}
}

void Game::EatDot()
{
	int &tileValue = pointsLayout[(int)(EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().y)][(int)(EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().x)];
	if (tileValue == 19)
	{
		tileValue = -19;
		score += 10;
	}
	else if (tileValue == 20)
	{
		tileValue = -20;
		score += 50;
	}
}

Game::~Game()
{
}
