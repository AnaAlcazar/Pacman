#include "Game.hpp"
#include "Renderer.hpp"
#include "FileReader.hpp"
#include "EntityManager.hpp"
#include "GameStateMachine.hpp"
#include <iostream>
#include "Pacman.hpp"
#include "Ghost.hpp"

Game::Game(int l)
{
	lives = 3;
	score = 0;
	highscore = 0;
	stage = 0;
	level = l;
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
	EntityManager::Instance().ResetAllPositions();
	timer = 0;
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
		EntityManager::Instance().ResetAllPositions();
		if (timer >= 3)
		{
			timer = 0;
			stage++;
		}
	}
	else if (stage == 1)	//Game Running
	{
		timer += GetFrameTime();
		for (int i = 1; i < 5; i++)
		{
			Entity* e = EntityManager::Instance().GetEntityAt(i);
			if ((e->GetTileOfEntity().x == 13 || e->GetTileOfEntity().x == 14) && e->GetTileOfEntity().y == 14 && !(dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i)))->Playing)
			{
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->ChangeMode(Ghost::Scatter);
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->DecideDirection(true);
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->Playing = true;
			}
			else if (timer >= (dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i)))->timerToStart + 0.2f && !(dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i)))->Playing)
			{
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->SetTargetTile({ 14,0 });
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->DecideDirection(true);
			}
			else if (timer >= (dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i)))->timerToStart && !(dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i)))->Playing)
			{
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->SetTargetTile({14,17});
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->DecideDirection(true);
			}
			else if (timer <(dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i)))->timerToStart && !(dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i)))->Playing)
			{
				Vector2 st = (EntityManager::Instance().GetEntityAt(i))->StartTile;
				float directioner = (int)(timer * 4) % 2 == 0 ? -1 : 1;
				st.y += directioner;
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->SetTargetTile(st);
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->DecideDirection(true);
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
	else if (stage == 4)		//Stopped for killing ghost
	{
		timer += GetFrameTime();
		if (timer >= 1)
		{
			timer = 0;
			stage = 1;
		}
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
	else if (stage == 3)
	{
		timer += GetFrameTime();
		if (timer >= 8)
		{
			if (lives > 0)
			{
				timer = 0;
				lives--;
				for (int i = 1; i < 5; i++)
				{
					Ghost* g = dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i));
					g->ResetPosition();
					g->targetTile = g->StartTile;
					g->Playing = false;
					g->ForceDirection({ -1,0 });
				}
				EntityManager::Instance().GetEntityAt(0)->ResetPosition();
				EntityManager::Instance().GetEntityAt(0)->ForceDirection({-1,0});
				stage = 0;
			}	
			else
			{
				if (timer >= 12)
				{
					Entity* p = EntityManager::Instance().GetEntityAt(0);
					Renderer::Instance().DrawText("Game Over!", 10, { 72, 160 }, 5);
					if (timer >= 15)
					{
						timer = 0;
						GameStateMachine::Instance().UseCoin();
						if (GameStateMachine::Instance().HasCoins())
							GameStateMachine::Instance().SetState(2);
						else
							GameStateMachine::Instance().SetState(0);
					}
				}
			}
		}
	}
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
	EntityManager::Instance().ResetEntities();
	FileReader::Instance().NewHighScore(highscore);
}

void Game::AddScore(int s)
{
	score += s;
}

int Game::GetStage()
{
	return stage;
}

void Game::SetStage(int s)
{
	stage = s;
}

Game::~Game()
{
}
