#pragma once
#include "raylib.h"
#include <vector>
using namespace std;

struct SpriteSheet
{
	Texture2D spritesheet;
	int spriteSize;
};

struct Animation
{
	int spritesheetIndex;
	int size;
	vector <int> sprites;
};

class Animator
{
private:
	int currentSprite;
	float timer;
	
public:
	vector <Animation> animations;
	Animator();
	void Animate(Vector2 pos_, int animIndex, float sp_, bool loop_);
	~Animator();
};

class Renderer
{
private:
	Renderer();
	vector <SpriteSheet> spritesheets;
	~Renderer();
public:
#pragma region Singleton
	static Renderer& Instance()
	{
		static Renderer instance;
		return instance;
	}
#pragma endregion
	Rectangle GetSpriteRectangle(int textureIndex, Vector2 texturePosition);
	Vector2 SpriteIndexToPosition(const int textureIndex, const int index);
	Color GetCustomColor(int index);
	void DrawSprite(int textureIndex, Vector2 texturePosition, Vector2 position, Color color);
	void DrawSprite(int textureIndex, Vector2 texturePosition, Vector2 position, int color);
	void DrawText(const char* text, const int length, Vector2 position, Color color);
	void DrawText(const char* text, const int length, Vector2 position, int color);
	void DrawNumber(int number, Vector2 position, Color color);
	void DrawNumber(int number, Vector2 position, int color);
	Vector2 AnchorNumberOnRight(int number, Vector2 initialPos);
};