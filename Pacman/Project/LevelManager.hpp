#pragma once
#include "raylib.h"
#include "Game.hpp"
#include <vector>

class LevelData
{
	int firstLevel;
	int lastLevel;
	Vector2 StagesTimes[5];
};

class LevelManager
{
	friend class Game;
};