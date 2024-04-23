#pragma once
#include "ScreenManager.hpp"
class GameStateMachine
{
private:
	int currentState;
	int nextState;
	void Start();
	void Input();
	void Logic();
	void Render();
	void End();
	bool IsSameState();
public:
	GameStateMachine();
	int GetState();
	int SetState(const int state_);
	void Run();
	GameStateMachine();
};