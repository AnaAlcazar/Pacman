#pragma once
#include "GameStateMachine.hpp"
#include "raylib.h"
#include "Renderer.hpp"
class Debugger
{
private:
	bool switches[10] = {false, false, false, false, false, false, false, false, false, false};
	void Switch(int i);
	Debugger() {};
	~Debugger() {};
public:
	static Debugger& Instance()
	{
		static Debugger instance;
		return instance;
	}
	bool GetSwitch(int i);
	void Input();
	void Render();
};