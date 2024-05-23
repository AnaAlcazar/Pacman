#include "raylib.h"
#include "MemLeaks.h"
#include "Globals.hpp"
#include "GameStateMachine.hpp"

int main()
{
	ReportMemoryLeaks();
	InitWindow(224 * SCALE_FACTOR, 288 * SCALE_FACTOR, "Pacman");
	if (FULLSCREEN)
	{
		SetWindowSize(GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor()));
		ToggleFullscreen();
	}

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