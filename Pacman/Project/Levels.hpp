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
		int mode_;
		float time;
	};
	float PacmanSpeedMultiplier;
	float GhostSpeedMultiplier;
	vector <GhostParameter*> GhostBehaviour;

public:
	Level(float p, float g);
	~Level();
	void GenerateGhostBehaviour(int m, float t);
	int GetModeInTime(float time, bool forceLevelMode);
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
	static LevelManager& Instance()
	{
		static LevelManager instance;
		return instance;
	}
	void Start(int l);
	void Logic();
	int RequestCurrentMode(bool forceLevelMode);
};