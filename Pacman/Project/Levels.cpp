#include "Levels.hpp"
#include "DataBase.hpp"

Level::Level(float PacmanSpeed_, float FrightPacmanSpeed_, float PacmanDotSpeed_, float FrightPacmanDotSpeed_, float GhostSpeed_, float FrightGhostSpeed_, float GhostTunnelSpeed_, int Blinky1Dots_, float Blinky1Speed_, int Blinky2Dots_, float Blinky2Speed_, float FrightTime_, int FrightFlashes_)
{
	PacmanSpeed = PacmanSpeed_;
	FrightPacmanSpeed = FrightPacmanSpeed_;
	PacmanDotSpeed = PacmanDotSpeed_;
	FrightPacmanDotSpeed = FrightPacmanDotSpeed_;
	GhostSpeed = GhostSpeed_;
	FrightGhostSpeed = FrightGhostSpeed_;
	GhostTunnelSpeed = GhostTunnelSpeed_;
	Blinky1Dots = Blinky1Dots_;
	Blinky1Speed = Blinky1Speed_;
	Blinky2Dots = Blinky2Dots_;
	Blinky2Speed = Blinky2Speed_;
	FrightTime = FrightTime_;
	FrightFlashes = FrightFlashes_;
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
	return PacmanSpeed;
}

float Level::GetGhostSpeed()
{
	return GhostSpeed;
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
	levelList = DataBase::Instance().GetOriginalLevels();
}

LevelManager::~LevelManager()
{
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

float LevelManager::RequestPacmanSpeed(bool pelletEffect, bool InDot)
{
	if (pelletEffect)
	{
		if (InDot) return levelList[currentLevel]->FrightPacmanDotSpeed;
		else return levelList[currentLevel]->FrightPacmanSpeed;
	}
	else
	{
		if (InDot) return levelList[currentLevel]->PacmanDotSpeed;
		else return levelList[currentLevel]->PacmanSpeed;
	}
}

float LevelManager::RequestGhostSpeed(bool tunnel, int dots, bool fright)
{
	if (tunnel)return levelList[currentLevel]->GhostTunnelSpeed;
	else if (fright)return levelList[currentLevel]->FrightGhostSpeed;
	else
	{
		if (dots == levelList[currentLevel]->Blinky1Dots)
			return levelList[currentLevel]->Blinky1Speed;
		else if (dots == levelList[currentLevel]->Blinky2Dots)
			return levelList[currentLevel]->Blinky2Speed;
		else
			return levelList[currentLevel]->GhostSpeed;
	}
}
