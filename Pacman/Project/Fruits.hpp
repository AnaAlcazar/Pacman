#pragma once
#include "raylib.h"
struct Fruit
{
	int ID;
	Vector2 TexturePos;
	int score;
	Vector2 levelsAppear;
};
class FruitManager
{
private:
	Vector2 spawnTile = {13.5f,18};
	int fruitRender[7];
	int renderOffset;
	float timer;
	int appearDots;
	bool appeared;
	bool collected;
	FruitManager();
	~FruitManager();
public:
	static FruitManager& Instance()
	{
		static FruitManager instance;
		return instance;
	}
	
	void Logic();
};