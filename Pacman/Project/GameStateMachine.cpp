#include "GameStateMachine.hpp"
#include "Game.hpp"
#include <iostream>

void GameStateMachine::Start()
{
	timer = 0;
	switch (currentState)
	{
	case 0:

		highscore = FileReader::Instance().ReadHighScore();
		break;
	case 1:
		game.Start();
		game.EnableAutopilot();
		break;
	case 2:
		highscore = FileReader::Instance().ReadHighScore();
		break;
	case 3:
		game = Game();
		game.Start();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
}

void GameStateMachine::Input()
{
	switch (currentState)
	{
	case 0:
		if (IsKeyPressed(KEY_TAB)) { coins++;  SetState(2); }
		break;
	case 1:
		if (IsKeyPressed(KEY_TAB)) { coins++;  SetState(2); }
		break;
	case 2:
		if (IsKeyPressed(KEY_TAB) && coins < 99)coins++;
		if (IsKeyPressed(KEY_ENTER))SetState(3);
		break;
	case 3:
		game.Input();
		//if(IsKeyPressed(KEY_KP_1))EntityManager::Instance().GetEntityAt(1).
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
	if (IsKeyPressed(KEY_KP_0))SetState(0);
	else if (IsKeyPressed(KEY_KP_1))SetState(1);
	else if (IsKeyPressed(KEY_KP_2))SetState(2);
	else if (IsKeyPressed(KEY_KP_3))SetState(3);
	else if (IsKeyPressed(KEY_KP_4))SetState(4);
	else if (IsKeyPressed(KEY_KP_5))SetState(5);
	else if (IsKeyPressed(KEY_KP_6))SetState(6);
}

void GameStateMachine::Logic()
{
	switch (currentState)
	{
	case 0:
		
		timer += GetFrameTime();
		if (timer > 32)SetState(1);
		break;
	case 1:
		game.Logic();
		break;
	case 2:
		break;
	case 3:
		game.Logic();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		while (timer < 3)
		{
			timer += GetFrameTime();
		}
		if (coins > 0)SetState(2);
		else SetState(0);
		break;
	default:
		break;
	}
}

void GameStateMachine::Render()
{
	switch (currentState)
	{
	case 0:
		ScreenManager::Instance().Render(0, WHITE);
		
		if (timer <= 3)
		{
			Renderer::Instance().DrawText("This game is for education", 26, { 8,8 }, WHITE);
			Renderer::Instance().DrawText("purpose created on project", 26, { 8,24 }, WHITE);
			Renderer::Instance().DrawText("1 of CITM university", 20, { 32,40 }, WHITE);
			Renderer::Instance().DrawText("No copyright intended ~", 23, { 20,272 }, WHITE);
		}
		else if (timer > 3 && timer <= 6)
		{
			Renderer::Instance().DrawSprite(3,{0,0},{144,144},WHITE);
			Renderer::Instance().DrawText("CITM - UPC", 10, { 72,24 }, WHITE);
			Renderer::Instance().DrawText("student        ana alcazar", 26, { 8,56 }, WHITE);
			Renderer::Instance().DrawText("tutor         jesus alonso", 26, { 8,72 }, WHITE);
			Renderer::Instance().DrawText("               marc torres", 26, { 8,88 }, WHITE);
		}
		else
		{
			
			Renderer::Instance().DrawText("   1UP   HIGH SCORE   2UP  ", 28, { 0,0 }, WHITE);
			Renderer::Instance().DrawText("00", 2, { 40,8 }, WHITE);
			Renderer::Instance().DrawNumber(highscore, Renderer::Instance().AnchorNumberOnRight( highscore, { 128,8 }), WHITE);
			Renderer::Instance().DrawText("  CREDIT 0", 10, { 0,280 }, WHITE);
			if (timer > 6.5f)Renderer::Instance().DrawText("       CHARACTER / NICKNAME ", 28, { 0,48 }, WHITE);
#pragma region Blinky
			if(timer > 7)Renderer::Instance().DrawSprite(0, { 0,2 }, { 40, 68 }, WHITE);
			if(timer > 7.5f)Renderer::Instance().DrawText("       -SHADOW", 14, { 0,64 }, 5);
			if(timer > 8)Renderer::Instance().DrawText("                  'BLINKY'  ", 28, { 0,64 }, 5);
#pragma endregion
#pragma region Pinky
			if (timer > 9)Renderer::Instance().DrawSprite(0, { 0,3 }, { 40, 92 }, WHITE);
			if (timer > 9.5f)Renderer::Instance().DrawText("       -SPEEDY", 14, { 0,88 }, 2);
			if (timer > 10)Renderer::Instance().DrawText("                  'PINKY'   ", 28, { 0,88 }, 2);
#pragma endregion
#pragma region Inky
			if (timer > 11)Renderer::Instance().DrawSprite(0, { 0,4 }, { 40, 116 }, WHITE);
			if (timer > 11.5f)Renderer::Instance().DrawText("       -BASHFUL", 15, { 0,112 }, 1);
			if (timer > 12)Renderer::Instance().DrawText("                  'INKY'    ", 28, { 0,112 }, 1);
#pragma endregion
#pragma region Clyde
			if (timer > 13)Renderer::Instance().DrawSprite(0, { 0,5 }, { 40, 140 }, WHITE);
			if (timer > 13.5f)Renderer::Instance().DrawText("       -POKEY", 13, { 0,136 }, 3);
			if (timer > 14)Renderer::Instance().DrawText("                  'CLYDE'    ", 28, { 0,136 }, 3);
#pragma endregion
			if (timer > 15) { 
				Renderer::Instance().DrawText("10 :", 6, { 96,200 }, WHITE); Renderer::Instance().DrawSprite(1, { 18,0 }, { 88, 204 }, 4);
				Renderer::Instance().DrawText("50 :", 6, { 96,216 }, WHITE); Renderer::Instance().DrawSprite(1, { 19,0 }, { 88, 220 }, 4);
			}
			if (timer > 16)
			{
				Renderer::Instance().DrawText("    ~ 1980 MIDWAY MFG. CO.   ", 28, { 0,248 }, 2);
				if(timer < 23.25f)
					Renderer::Instance().DrawSprite(1, { 19,0 }, { 36, 176 }, 4);
			}
			if (timer > 17)
			{
				if (timer < 23.25f)
				{
					float pacPos = 224 -(timer-17)*30;
					float bPos = 280 - (timer - 17) * 30;
					float pPos = 296 - (timer - 17) * 30;
					float iPos = 312 - (timer - 17) * 30;
					float cPos = 328 - (timer - 17) * 30;
					pellet.Animate({ 36, 176 }, 0, 0.1f, true);
					pacman.Animate({ pacPos, 176 }, 0, 0.1f, true);
					b.Animate({ bPos, 176 }, 0, 0.1f, true);
					p.Animate({ pPos, 176 }, 0, 0.1f, true);
					i.Animate({ iPos, 176 }, 0, 0.1f, true);
					c.Animate({ cPos, 176 }, 0, 0.1f, true);
				}
				else
				{
					float pacPos = 36 + (timer - 23.25f) * 30;
					float bPos = 92 + (timer - 23.25f) * 12;
					float pPos = 108 + (timer - 23.25f) * 12;
					float iPos = 124 + (timer - 23.25f) * 12;
					float cPos = 140 + (timer - 23.25f) * 12;
					pacman.Animate({ pacPos, 176 }, 1, 0.1f, true);
					b.Animate({ bPos, 176 }, 1, 0.1f, true);
					p.Animate({ pPos, 176 }, 1, 0.1f, true);
					i.Animate({ iPos, 176 }, 1, 0.1f, true);
					c.Animate({ cPos, 176 }, 1, 0.1f, true);
				}
			}
		}
		break;
	case 1:
		ScreenManager::Instance().Render(1, 0);
		game.Render();
		break;
	case 2:
		ScreenManager::Instance().Render(0, WHITE);
		Renderer::Instance().DrawText("   1UP   HIGH SCORE   2UP  ", 28, { 0,0 }, WHITE);
		Renderer::Instance().DrawText("00", 2, { 40,8 }, WHITE);
		Renderer::Instance().DrawText("  CREDIT", 8, { 0,280 }, WHITE);
		Renderer::Instance().DrawNumber(coins,{72, 280}, WHITE);
		Renderer::Instance().DrawNumber(highscore, Renderer::Instance().AnchorNumberOnRight(highscore, { 128,8 }), WHITE);
		Renderer::Instance().DrawText("      PUSH START BUTTON      ", 28, { 0,136 }, 3);
		Renderer::Instance().DrawText(" BONUS PAC-MAN FOR 10000 : ", 28, { 0,184 }, 4);
		Renderer::Instance().DrawText("    ~ 1980 MIDWAY MFG.CO.   ", 28, { 0,208 }, 2);
		if(coins < 2) Renderer::Instance().DrawText("        1 PLAYER ONLY        ", 28, { 0,160 }, 1);
		else Renderer::Instance().DrawText("        1 OR 2 PLAYERS       ", 28, { 0,160 }, 1);
		break;
	case 3:
		ScreenManager::Instance().Render(1, 0);
		game.Render();
		break;
	case 4:
		ScreenManager::Instance().Render(1, WHITE);
		break;
	case 5:
		ScreenManager::Instance().Render(1, 0);
		Renderer::Instance().DrawText("GAME OVER!", 10, { 72,160 }, 5);
		break;
	case 6:
		ScreenManager::Instance().Render(0, WHITE);
		break;
	default:
		break;
	}
	
}

void GameStateMachine::End()
{
	switch (currentState)
	{
	case 0:
		break;
	case 1:
		game.End();
		break;
	case 2:
		break;
	case 3:
		game.End();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
	currentState = nextState;
}

bool GameStateMachine::IsSameState()
{
	return currentState == nextState?true:false;
}

GameStateMachine::GameStateMachine()
{
	currentState = 0;
	nextState = 0;
	coins = 0;
	timer = 0;
	highscore = FileReader::Instance().ReadHighScore();
	Animation pellet_ = { 1,2 };
	pellet_.sprites.push_back(19);
	pellet_.sprites.push_back(-1);
	pellet.animations.push_back(pellet_);
	Animation pacmanL = { 0,4 };
	pacmanL.sprites.push_back(0);
	pacmanL.sprites.push_back(17);
	pacmanL.sprites.push_back(16);
	pacmanL.sprites.push_back(17);
	pacman.animations.push_back(pacmanL);
	Animation pacmanR = { 0,4 };
	pacmanR.sprites.push_back(0);
	pacmanR.sprites.push_back(21);
	pacmanR.sprites.push_back(20);
	pacmanR.sprites.push_back(21);
	pacman.animations.push_back(pacmanR);
	Animation gv = { 0,2 };
	gv.sprites.push_back(36);
	gv.sprites.push_back(37);
	Animation bL = { 0,2 };
	bL.sprites.push_back(30);
	bL.sprites.push_back(31);
	b.animations.push_back(bL);
	b.animations.push_back(gv);
	Animation pL = { 0,2 };
	pL.sprites.push_back(44);
	pL.sprites.push_back(45);
	p.animations.push_back(pL);
	p.animations.push_back(gv);
	Animation iL = { 0,2 };
	iL.sprites.push_back(58);
	iL.sprites.push_back(59);
	i.animations.push_back(iL);
	i.animations.push_back(gv);
	Animation cL = { 0,2 };
	cL.sprites.push_back(72);
	cL.sprites.push_back(73);
	c.animations.push_back(cL);
	c.animations.push_back(gv);
}

GameStateMachine::~GameStateMachine()
{
}

int GameStateMachine::GetState()
{
	return nextState;
}

void GameStateMachine::SetState(const int state_)
{
	nextState = state_;
}

void GameStateMachine::Run()
{
	Start();
	while (nextState != -1 && !WindowShouldClose() && IsSameState())
	{
		ClearBackground(BLACK);
		Input();
		Logic();
		BeginDrawing();
		Render();
		EndDrawing();
	}
	End();
}
