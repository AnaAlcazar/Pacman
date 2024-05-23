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

float Level::GetPacmanSpeed()
{
	return PacmanSpeedMultiplier;
}

float Level::GetGhostSpeed()
{
	return GhostSpeedMultiplier;
}

void Level::GenerateGhostBehaviour(int m, float t)
{
	GhostParameter* ngp = new GhostParameter;
	ngp->mode_ = m;
	ngp->time = t;
	GhostBehaviour.push_back(ngp);
}

int Level::GetModeInTime(float time, bool forceLevelMode)
{
	if (dynamic_cast <Pacman*>(EntityManager::Instance().GetEntityAt(0))->HasPelletEffect() && !forceLevelMode)
		return Ghost::Frightened;
	float totalTime = GhostBehaviour.at(0)->time;
	int index = 0;
	for (int i = index; i < GhostBehaviour.size(); i++, index++)
	{
		totalTime+= GhostBehaviour.at(0)->time;
		if (totalTime >= time)
			break;
	}
	if (index >= GhostBehaviour.size())
		index = GhostBehaviour.size() - 1;
	return GhostBehaviour.at(index)->mode_;
}

LevelManager::LevelManager()
{
	Start(1);
	#pragma region Level 1
		Level* l1 = new Level(1,1);
		l1->GenerateGhostBehaviour(Ghost::Scatter, 7);
		l1->GenerateGhostBehaviour(Ghost::Chase, 20);
		l1->GenerateGhostBehaviour(Ghost::Scatter, 7);
		l1->GenerateGhostBehaviour(Ghost::Chase, 20);
		l1->GenerateGhostBehaviour(Ghost::Scatter, 5);
		l1->GenerateGhostBehaviour(Ghost::Chase, 20);
		l1->GenerateGhostBehaviour(Ghost::Scatter, 5);
		l1->GenerateGhostBehaviour(Ghost::Chase, 20);
		levelList.push_back(l1);
	#pragma endregion
}

LevelManager::~LevelManager()
{
	for (int i = 0; i < levelList.size(); i++)
	{
		delete levelList[i];
	}
	levelList.clear();
}

void LevelManager::Start(int l)
{
	currentLevel = l;
	if(currentLevel >= levelList.size())
		currentLevel = levelList.size()-1;
	currentStage = 0;
	timer = 0;
}

void LevelManager::Logic()
{
	if (!dynamic_cast<Pacman*>(EntityManager::Instance().GetEntityAt(0))->HasPelletEffect())
		timer += GetFrameTime();
}

int LevelManager::RequestCurrentMode(bool forceLevelMode)
{
	return (*levelList[currentLevel]).GetModeInTime(timer, forceLevelMode);
}

int LevelManager::RequestPacmanSpeedMultiplier()
{
	return levelList[currentLevel]->GetPacmanSpeed();
}

int LevelManager::RequestGhostSpeedMultiplier()
{
	return levelList[currentLevel]->GetGhostSpeed();
}