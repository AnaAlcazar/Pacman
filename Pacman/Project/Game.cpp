#include "Game.hpp"
#include "Renderer.hpp"
#include "FileReader.hpp"
#include "EntityManager.hpp"
#include <iostream>
#include "Pacman.hpp"

Game::Game()
{
	lives = 3;
	score = 0;
	highscore = 0;
	stage = 0;
	autopilot = false;
	eatenDots = 0;
	timer = 0;
}

void Game::EnableAutopilot()
{
	autopilot = true;
}

void Game::Start()
{
	highscore = FileReader::Instance().ReadHighScore();
	score = 0;
	ResetLayout();
}

void Game::Input()
{
	if(stage == 1)
		EntityManager::Instance().Input();
}

void Game::Logic()
{
	if (stage == 0)		//Ready text
	{
		timer += GetFrameTime();
		if (timer >= 3)
		{
			timer = 0;
			stage++;
		}
	}
	else if (stage == 1)	//Game Running
	{
		if (autopilot)
		{
			for (int i = 0; i < Instructions.size(); i++)
			{
				if (Instructions[i].done)continue;
				else if (!(Instructions[i].tile.x == EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().x) || !(Instructions[i].tile.y == EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().y) || EntityManager::Instance().GetEntityAt(0)->EntityIsCenteredInTile(EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity()))break;
				EntityManager::Instance().GetEntityAt(0)->TrySetDirection(Instructions[i].dir);
			}
		}
		
		EatDot();
		EntityManager::Instance().Logic();
	}
	else if (stage == 2)		//Level Cleared
	{

	}
	else if (stage == 3)		//Pacman Dying
	{

	}

	if (!autopilot && score > highscore)highscore = score;
}

void Game::Render()
{
	RenderPoints();
	EntityManager::Instance().Render();
	Renderer::Instance().DrawText("   1UP   HIGH SCORE   2UP  ", 28, { 0,0 }, WHITE);
	Renderer::Instance().DrawNumber(score, Renderer::Instance().AnchorNumberOnRight(score, {48,8}), WHITE);
	Renderer::Instance().DrawNumber(highscore, Renderer::Instance().AnchorNumberOnRight(score, { 128,8 }), WHITE);
	for (int i = 0; i < lives-1; i++)
	{
		Renderer::Instance().DrawSprite(0,{(float)8,(float)1},{(float)(24+16*i),(float) 280}, WHITE);
	}
	if (stage == 0)Renderer::Instance().DrawText("Ready!", 6, { 92, 160 }, 6);
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
		dynamic_cast<Pacman*>(EntityManager::Instance().GetEntityAt(0))->EatPellet();
	}
	else return;
	eatenDots++;
}

void Game::End()
{
	if(!autopilot)
		FileReader::Instance().NewHighScore(highscore);
}

Game::~Game()
{
	Instructions.clear();
}
