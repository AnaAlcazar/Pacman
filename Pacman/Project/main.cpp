#include "raylib.h"
#include "GameStateMachine.hpp"

int main()
{
	InitWindow(224, 288, "Pacman");
	SetTargetFPS(60);
	InitAudioDevice();
#pragma region Variables
#pragma endregion
	while (!WindowShouldClose() && !(GameStateMachine::Instance().GetState() == -1))
	{
		GameStateMachine::Instance().Run();
	}

	CloseAudioDevice();
	CloseWindow();
	return 0;
}