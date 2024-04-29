#pragma once
#include "raylib.h"
#include <vector>
using namespace std;

struct SpriteSheet
{
	Texture2D spritesheet;
	int spriteSize;
};
class Renderer
{
private:
	Renderer();
	vector <SpriteSheet> spritesheets;
	~Renderer() {};
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
	void DrawText(char* text, int length, Vector2 position, Color color);
	void DrawText(char* text, int length, Vector2 position, int color);
	bool IsAnimationFinished();
	void Animate(int textureIndex, Vector2* sprites, int spriteLength, Color* colors, int colorLength, bool loop);
	void Animate(int textureIndex, Vector2* sprites, int spriteLength, int* colors, int colorLength, bool loop);
};