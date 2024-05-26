#include "Debugger.hpp"

void Debugger::Switch(int i)
{
	switches[i] = !switches[i];
}

bool Debugger::GetSwitch(int i)
{
	return switches[i];
}

void Debugger::Input()
{
	if (IsKeyDown(KEY_F1))Switch(0);
	if (IsKeyDown(KEY_F2))Switch(1);
	if (IsKeyDown(KEY_F3))Switch(2);
	if (IsKeyDown(KEY_F4))Switch(3);
	if (IsKeyDown(KEY_F5))Switch(4);
	if (IsKeyDown(KEY_F6))Switch(5);
	if (IsKeyDown(KEY_F7))Switch(6);
	if (IsKeyDown(KEY_F8))Switch(7);
	if (IsKeyDown(KEY_F9))Switch(8);
}

void Debugger::Render()
{
	if (GetSwitch(0))Renderer::Instance().DrawText("GOD MODE ON", 11, { -104, 8 }, WHITE);
	if (GetSwitch(1))
	{
		Renderer::Instance().DrawText("LEVEL", 5, { -104, 32 }, WHITE);
		Renderer::Instance().DrawNumber(GameStateMachine::Instance().game->GetLevel() + 1, Renderer::Instance().AnchorNumberOnRight(GameStateMachine::Instance().game->GetLevel() + 1, { -16, 32 }), WHITE);
		Renderer::Instance().DrawText("DOTS    /244", 12, { -104, 40 }, WHITE);
		Renderer::Instance().DrawNumber(GameStateMachine::Instance().game->GetEatenDots(), Renderer::Instance().AnchorNumberOnRight(GameStateMachine::Instance().game->GetEatenDots(), { -48, 40 }), WHITE);
		Renderer::Instance().DrawText("FRUITS    /2", 12, { -104, 48 }, WHITE);
		Renderer::Instance().DrawNumber(FruitManager::Instance().GetAppearedFruits(), Renderer::Instance().AnchorNumberOnRight(FruitManager::Instance().GetAppearedFruits(), {-32, 48}), WHITE);
	}
	if (GetSwitch(2))
	{
		for (int y = 0; y < 36; y++)
		{
			for (int x = 0; x < 28; x++)
			{
				if (ScreenManager::Instance().IsTangible({(float)x,(float)y}) || ScreenManager::Instance().Empty({ (float)x,(float)y }))continue;
				DrawRectangleLinesEx({ (float)x * 8 * SCALE_FACTOR,(float)y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 1, GREEN);
			}
		}
		Renderer::Instance().DrawText("COLLIDERS ON", 12, { -104, 16 }, WHITE);
	}
}
