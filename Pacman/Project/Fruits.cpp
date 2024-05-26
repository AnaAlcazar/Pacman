#include "Fruits.hpp"
#include "GameStateMachine.hpp"
#include "EntityManager.hpp"
#include "Renderer.hpp"
#include "Globals.hpp"

FruitManager::FruitManager()
{
#pragma region Fruits
	Fruit cherry{ {10, 2},{9,1}, 100, {1,1} };
	Fruit strawberry{ {10, 3},{11,1}, 300, {2,2} };
	Fruit orange{ {10, 4},{13,0}, 500, {3,4} };
	Fruit apple{ {10, 5},{12,1}, 700, {5,6} };
	Fruit melon{ {11, 2},{13,2}, 1000, {7,8} };
	Fruit galaxian{ {11, 3},{13,4}, 2000, {9,10} };
	Fruit bell{ {11, 4},{13,5}, 3000, {11,12} };
	Fruit key{ {11, 5},{13,6}, 5000, {13,255} };
	fruits[0] = cherry;
	fruits[1] = strawberry;
	fruits[2] = orange;
	fruits[3] = apple;
	fruits[4] = melon;
	fruits[5] = galaxian;
	fruits[6] = bell;
	fruits[7] = key;
#pragma endregion
	spawnTile = { 14,20.5f };
	for (int i = 0; i < 7; i++)
	{
		fruitRender[i] = -1;
	}
	Start(GameStateMachine::Instance().game->GetLevel());
}

FruitManager::~FruitManager()
{

}

void FruitManager::Start(int l)
{
	level = l+1;
	timer = 0;
	appeared = 0;
	collected = false;
	inScene = false;
	UpdateLevelCounter();
}

void FruitManager::Logic()
{
	if ((GameStateMachine::Instance().game->GetEatenDots() >= 70 && appeared == 0) || (GameStateMachine::Instance().game->GetEatenDots() >= 170 && appeared == 1))
	{
		inScene = true;
		collected = false;
		appeared++;
	}

	if (inScene)
	{
		timer += GetFrameTime();
		if (timer >= 10)
		{
			timer = 0;
			inScene = false;
		}

		if (EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().x == (int)spawnTile.x && EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().y == (int)spawnTile.y)
		{
			AudioManager::Instance().PlaySoundByName("Eat_Fruit");
			timer = 0;
			inScene = false;
			collected = true;
			GameStateMachine::Instance().game->AddScore(GetFruitOfLevel().score);
		}
	}

	if (collected)
	{
		timer += GetFrameTime();
		if (timer >= 2)
		{
			timer = 0;
			collected = false;
		}
	}
}

void FruitManager::Render()
{
	if (inScene)
		Renderer::Instance().DrawSprite(0, GetFruitOfLevel().TexturePos, { spawnTile.x * 8, spawnTile.y*8 }, WHITE);

	if (collected)
	{
		Renderer::Instance().DrawSprite(0, GetFruitOfLevel().ScoreTexturePos, { spawnTile.x * 8, spawnTile.y * 8 }, WHITE);
		if(GetFruitOfLevel().score >= 1000)
			Renderer::Instance().DrawSprite(0, {GetFruitOfLevel().ScoreTexturePos.x - 1,GetFruitOfLevel().ScoreTexturePos.y }, { (spawnTile.x-2) * 8, spawnTile.y * 8 }, WHITE);
	}
	
	for (int i = 0; i < 7; i++)
	{
		if(fruitRender[i]!= -1)
			Renderer::Instance().DrawSprite(0, fruits[fruitRender[i]].TexturePos, { (float)(112 + 16 * i), 280 }, WHITE);
	}
}

void FruitManager::UpdateLevelCounter()
{
	int l = level;
	int renderFruits[7] = { -1,-1,-1,-1,-1,-1,-1 };
	int offset = 0;
	int margin = 0;

	while (l > 0 && offset < 7)
	{
		for (int i = 7; i >= 0; i--)
		{
			if (fruits[i].levelsAppear.x <= l && fruits[i].levelsAppear.y >= l)
			{
				renderFruits[offset] = i;
				offset++;
				l--;
				if (l == 0)
				{
					margin = 7 - offset;
				}
				break;
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		if (i < margin)fruitRender[i] = -1;
		else fruitRender[i] = renderFruits[i - margin];
	}
}

void FruitManager::QuitFruit()
{
	inScene = false;
}

Fruit FruitManager::GetFruitOfLevel()
{
	for (int i = 0; i < 8; i++)
	{
		if (fruits[i].levelsAppear.x <= level && fruits[i].levelsAppear.y >= level)
		{
			return fruits[i];
		}
		else continue;
	}
}

int FruitManager::GetAppearedFruits()
{
	return appeared;
}
