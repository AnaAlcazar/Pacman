#include "Fruits.hpp"

FruitManager::FruitManager()
{
	spawnTile = { 13.5f,18 };
	renderOffset = 6;
	timer = 0;
	appearDots = 100;
	for (int i = 0; i < 7; i++)
	{
		fruitRender[i] = -1;
	}
}

FruitManager::~FruitManager()
{
}
