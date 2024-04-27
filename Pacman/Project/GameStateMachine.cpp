#include "GameStateMachine.hpp"

void GameStateMachine::Start()
{
	switch (currentState)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
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
		break;
	case 1:
		if (IsKeyPressed(KEY_TAB))SetState(2);
		break;
	case 2:
		if (IsKeyPressed(KEY_TAB))coins++;
		if (IsKeyPressed(KEY_ENTER))SetState(3);
		break;
	case 3:
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

void GameStateMachine::Logic()
{
	switch (currentState)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
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
		screens.Render(0, WHITE);
		break;
	case 1:
		screens.Render(1, 0);
		break;
	case 2:
		screens.Render(0, WHITE);
		break;
	case 3:
		screens.Render(1, 0);
		break;
	case 4:
		screens.Render(1, WHITE);
		break;
	case 5:
		screens.Render(1, 0);
		break;
	case 6:
		screens.Render(0, WHITE);
		break;
	default:
		break;
	}
	
}

void GameStateMachine::End()
{
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
