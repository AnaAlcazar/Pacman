#pragma once
#include <vector>
#include "Ghost.hpp"
class Level
{
protected:
	struct GhostParameter
	{
		Ghost::Mode mode_;
		float time;
	};
	int ID;
	float PacmanSpeedMultiplier;
	float GhostSpeedMultiplier;
	vector <GhostParameter*> GhostBehaviour;

public:
	Level(int ID_, float p, float g);
	~Level();
	void GenerateGhostBehaviour(Ghost::Mode m, float t);
	Ghost::Mode GetModeInTime(float time);
};