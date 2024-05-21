#include "Levels.hpp"

Level::Level(float p, float g)
{
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
	for (int i = index; i < GhostBehaviour.size(); i++, index++)
	{
		totalTime+= GhostBehaviour.at(0)->time;
		if (totalTime >= time)
			break;
	}
	return GhostBehaviour.at(index)->mode_;
}

LevelManager::~LevelManager()
{
	for (int i = 0; i < levelList.size(); i++)
	{
		delete &levelList[i];
	}
	levelList.clear();
}

void LevelManager::Start()
{
	timer = 0;
}

void LevelManager::Logic()
{
	timer += GetFrameTime();
}

Ghost::Mode LevelManager::RequestCurrentMode()
{
	return levelList[currentLevel].GetModeInTime(timer);
}
