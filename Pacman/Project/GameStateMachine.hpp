#pragma once
#include "ScreenManager.hpp"
#include "EntityManager.hpp"
class GameStateMachine
{
private:
	int currentState;
	int nextState;
	int coins;
	float timer;
	ScreenManager screens;
	void Start();
	void Input();
	void Logic();
	void Render();
	void End();
	bool IsSameState();
	GameStateMachine();
	~GameStateMachine();
public:
	static GameStateMachine& Instance()
	{
		static GameStateMachine instance;
		return instance;
	};
	int GetState();
	void SetState(const int state_);
	void Run();
	
};