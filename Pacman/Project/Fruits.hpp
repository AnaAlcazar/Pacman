#pragma once
#include <vector>
#include "raylib.h"
struct Fruit
{
	Vector2 TexturePos;
	Vector2 ScoreTexturePos;
	int score;
	Vector2 levelsAppear;
};
class FruitManager
{
private:
	Fruit fruits[8];
	Vector2 spawnTile = {13.5f,18};
	int fruitRender[7];
	int renderOffset;
	float timer;
	int appeared;
	bool inScene;
	bool collected;
	int level;
	FruitManager();
	~FruitManager();
public:
	static FruitManager& Instance()
	{
		static FruitManager instance;
		return instance;
	}
	void Start(int l);
	void Logic();
	Fruit GetFruitOfLevel();
	void QuitFruit();
	void Render();
	void UpdateLevelCounter();
};