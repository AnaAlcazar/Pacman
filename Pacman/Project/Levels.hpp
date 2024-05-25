#pragma once
#include <vector>
#include "Ghost.hpp"
#include "Pacman.hpp"
#include "raylib.h"
class Level
{
	friend class LevelManager;
protected:
	struct GhostParameter
	{
		int mode_;
		float time;
	};
	float PacmanSpeed;
	float FrightPacmanSpeed;
	float PacmanDotSpeed;
	float FrightPacmanDotSpeed;
	float GhostSpeed;
	float FrightGhostSpeed;
	float GhostTunnelSpeed;
	int Blinky1Dots;
	float Blinky1Speed;
	int Blinky2Dots;
	float Blinky2Speed;
	float FrightTime;
	int FrightFlashes;
	vector <GhostParameter*> GhostBehaviour;

public:
	Level(float PacmanSpeed_, float FrightPacmanSpeed_, float PacmanDotSpeed_,
	float FrightPacmanDotSpeed_, float GhostSpeed_, float FrightGhostSpeed_,
	float GhostTunnelSpeed_, int Blinky1Dots_,	float Blinky1Speed_,
	int Blinky2Dots_, float Blinky2Speed_, float FrightTime_, int FrightFlashes_);
	~Level();
	float GetPacmanSpeed();
	float GetGhostSpeed();
	void GenerateGhostBehaviour(int m, float t);
	int GetModeInTime(float time, bool forceLevelMode);
};

class LevelManager
{
private:
	int currentLevel;
	int currentStage;
	float timer;
	vector <Level*> levelList;
	LevelManager();
	~LevelManager();
public:
	static LevelManager& Instance()
	{
		static LevelManager instance;
		return instance;
	}
	void Start(int l);
	void Logic();
	int RequestCurrentMode(bool forceLevelMode);
	float RequestPacmanSpeed(bool pelletEffect, bool InDot);
	float RequestGhostSpeed(bool tunnel, int dots, bool fright);
	int RequestPelletTime();
};