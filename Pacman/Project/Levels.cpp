#include "Levels.hpp"

Level::Level(int ID_, float p, float g)
{
	ID = ID_;
	PacmanSpeedMultiplier = p;
	GhostSpeedMultiplier = g;
}

Level::~Level()
{
	for (int i = 0; i < GhostBehaviour.size(); i++)
	{
		delete GhostBehaviour[i];
	}
	GhostBehaviour.clear();
}

void Level::GenerateGhostBehaviour(Ghost::Mode m, float t)
{
	GhostParameter ngp;
	ngp.mode_ = m;
	ngp.time = t;
	GhostBehaviour.push_back(&ngp);
}

Ghost::Mode Level::GetModeInTime(float time)
{
	float totalTime = GhostBehaviour.at(0)->time;
	int index = 1;
	while (totalTime < time)
	{
		totalTime+= GhostBehaviour.at(index)->time;
		index++;
	}
	return GhostBehaviour.at(0)->mode_;
}
