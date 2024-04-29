#include "raylib.h"
#include "MemLeaks.h"
#include "GameStateMachine.hpp"

int main()
{
	ReportMemoryLeaks();
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