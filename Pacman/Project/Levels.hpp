#pragma once
#include <vector>
#include "Ghost.hpp"
#include "Pacman.hpp"
#include "raylib.h"
class Level
{
protected:
	struct GhostParameter
	{
		Ghost::Mode mode_;
		float time;
	};
	float PacmanSpeedMultiplier;
	float GhostSpeedMultiplier;
	vector <GhostParameter*> GhostBehaviour;

public:
	Level(float p, float g);
	~Level();
	void GenerateGhostBehaviour(Ghost::Mode m, float t);
	Ghost::Mode GetModeInTime(float time);
};

class LevelManager
{
private:
	int currentLevel;
	int currentStage;
	float timer;
	vector <Level> levelList;
	LevelManager();
	~LevelManager();
public:
	void Start();
	void Logic();
	Ghost::Mode RequestCurrentMode();
};