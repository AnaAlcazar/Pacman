#include "Game.hpp"
#include "Renderer.hpp"

Game::Game()
{
	lives = 3;
	score = 0;

}

void Game::Input()
{
	EntityManager::Instance().Input();
}

void Game::Logic()
{
	EntityManager::Instance().Logic();
}

void Game::Render()
{
	EntityManager::Instance().Render();
	RenderPoints();
}

void Game::ResetLayout()
{
	for (int y = 0; y < 36; y++)
	{
		for (int x = 0; x < 28; x++)
		{
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

Game::~Game()
{
}
