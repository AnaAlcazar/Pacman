#include "raylib.h"
#include "MemLeaks.h"
#include "Globals.hpp"
#include "GameStateMachine.hpp"

int main()
{
	ReportMemoryLeaks();
	InitWindow(224*SCALE_FACTOR, 288*SCALE_FACTOR, "Pacman");
	SetWindowPosition((GetMonitorWidth(GetCurrentMonitor())) / 2 - 112 * SCALE_FACTOR, (GetMonitorHeight(GetCurrentMonitor())) / 2 - 144 * SCALE_FACTOR);
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