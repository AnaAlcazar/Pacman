#include "Game.hpp"
#include "Renderer.hpp"
#include "FileReader.hpp"
#include "EntityManager.hpp"
#include "GameStateMachine.hpp"
#include <iostream>
#include "Pacman.hpp"
#include "Ghost.hpp"

Game::Game()
{
	lives = 3;
	score = 0;
	highscore = 0;
	stage = 0;
	level = 0;
	eatenDots = 0;
	timer = 0;
}

void Game::Start()
{
	highscore = FileReader::Instance().ReadHighScore();
	score = 0;
	ResetLayout();
	EntityManager::Instance().ResetAllPositions();
	dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(1))->stage = 2;
	dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(2))->stage = 1;
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
			stage = 1;
		}
	}
	else if (stage == 1)	//Game Running
	{
		
		bool ghostInBox = false;
		for (int i = 1; i < 5; i++)
		{
			Ghost* e = dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i));
			if (e->stage < 4)
			{
				ghostInBox = true;
				break;
			}
		}
		if(ghostInBox)
			timer += GetFrameTime();

		
		for (int i = 1; i < 5; i++)
		{
			Ghost* e = dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i));
			#pragma region Setting Target
			if (e->stage == 0)
			{
				Vector2 st = (EntityManager::Instance().GetEntityAt(i))->StartTile;
				float directioner = (int)(timer * 4) % 2 == 0 ? -1 : 1;
				st.y += directioner;
				
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->SetTargetTile(st);
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->DecideDirection(true);
			}
			else if (e->stage == 1)
			{
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->SetTargetTile({14, 17});
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->DecideDirection(true);
			}
			else if (e->stage == 2)
			{
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->SetTargetTile({ 13, 14 });
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->DecideDirection(true);
			}
			else if (e->stage == 3)
			{
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->ChangeMode(Ghost::Mode::Scatter);
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i))->DecideDirection(false);
				e->stage++;
			}
			if (eatenDots == 244)stage = 2;
#pragma endregion

#pragma region Changing Stage
			if (e->stage == 0 && dynamic_cast<Ghost*>(e)->timerToStart < timer)
				e->stage++;
			else if (e->stage == 1 && (e->GetTileOfEntity().x == 13 || e->GetTileOfEntity().x == 14) && e->GetTileOfEntity().y == 17)
				e->stage++;
			else if (e->stage == 2 &&(e->GetTileOfEntity().x == 13 || e->GetTileOfEntity().x == 14) && e->GetTileOfEntity().y == 14)
				e->stage++;
#pragma endregion
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

	if (score > highscore)highscore = score;
}

void Game::Render()
{
	#pragma region General
	RenderPoints();
	
	Renderer::Instance().DrawText("   1UP   HIGH SCORE   2UP  ", 28, { 0,0 }, WHITE);
	Renderer::Instance().DrawNumber(score, Renderer::Instance().AnchorNumberOnRight(score, {48,8}), WHITE);
	Renderer::Instance().DrawNumber(highscore, Renderer::Instance().AnchorNumberOnRight(score, { 128,8 }), WHITE);
	
#pragma endregion
	EntityManager::Instance().Render();
	if (stage == 0)
	{
		Renderer::Instance().DrawText("Ready!", 6, { 92, 160 }, 6);

		Renderer::Instance().DrawSprite(1, { 19,1 }, { 13.5*8*SCALE_FACTOR,15.5 * 8 * SCALE_FACTOR }, WHITE);
		Renderer::Instance().DrawSprite(1, { 19,1 }, { 14.5 * 8 * SCALE_FACTOR,15.5 * 8 * SCALE_FACTOR }, WHITE);
	}
	else if (stage == 1)
	{
		#pragma region Run
		for (int i = 0; i < lives - 1; i++)
		{
			Renderer::Instance().DrawSprite(0, { (float)8,(float)1 }, { (float)(24 + 16 * i),(float)280 }, WHITE);
		}
#pragma endregion
	}
	else if (stage == 2)
	{

	}
	else if (stage == 3)
	{
		#pragma region Pacman killed
		Pacman* p = dynamic_cast<Pacman*>(EntityManager::Instance().GetEntityAt(0));
		cout << p->GetPelletMultiplier() << endl;
		timer += GetFrameTime();
		p->Render();
		if (!p->IsAlive())
		{
			lives--;
			p->Revive();
		}
		
		if (timer >= 8)
		{
			if (lives > 0)
			{
				for (int i = 1; i < 5; i++)
				{
					Ghost* g = dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(i));
					g->ResetPosition();
					g->targetTile = g->StartTile;
					g->stage = 0;
					g->ForceDirection({ -1,0 });
				}
				
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(1))->stage = 2;
				dynamic_cast<Ghost*>(EntityManager::Instance().GetEntityAt(2))->stage = 1;
				if (timer >= 12)
				{
					EntityManager::Instance().GetEntityAt(0)->ResetPosition();
					EntityManager::Instance().GetEntityAt(0)->ForceDirection({ -1,0 });
					stage = 0;
					timer = 0;
				}
			}
			else if (lives <= 0)
			{
				if (timer >= 12)
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
#pragma endregion
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