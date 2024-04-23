#include "raylib.h"
#include "GameStateMachine.hpp"

int main()
{
	InitWindow(224, 288, "Pacman");
	InitAudioDevice();
#pragma region Variables
	GameStateMachine gameState;
#pragma endregion


	CloseAudioDevice();
	CloseWindow();
	return 0;
}