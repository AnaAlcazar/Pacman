#include "Renderer.hpp"
#include "Globals.hpp"
#include "CustomColors.hpp"
#include <iostream>
#include <string>
using namespace std;
Renderer::Renderer()
{
	SpriteSheet general{ LoadTexture("assets/sprites/General.png"), 16};
	SpriteSheet map{ LoadTexture("assets/sprites/Map.png"), 8 };
	SpriteSheet text{ LoadTexture("assets/sprites/Text.png"), 8 };
	SpriteSheet citm{ LoadTexture("assets/sprites/CITMBackground.png"), 288 };
	spritesheets.push_back(general);
	spritesheets.push_back(map);
	spritesheets.push_back(text);
	spritesheets.push_back(citm);
}

Rectangle Renderer::GetSpriteRectangle(int textureIndex, Vector2 texturePosition)
{
	if (textureIndex >= 0)
	{
		Rectangle sprite = { spritesheets[textureIndex].spriteSize * texturePosition.x,
								spritesheets[textureIndex].spriteSize * texturePosition.y,
								spritesheets[textureIndex].spriteSize, spritesheets[textureIndex].spriteSize };
		return sprite;
	}
	else
	{
		return Rectangle();
	}
}

Color Renderer::GetCustomColor(int index)
{
	if(index == 0)return Color(MAP_BLUE);
	else if (index == 1)return Color(TEXT_BLUE);
	else if (index == 2)return Color(TEXT_PINK);
	else if (index == 3)return Color(TEXT_ORANGE);
	else if (index == 4)return Color(TEXT_OCHER);
	else if (index == 5)return Color(TEXT_RED);
	else if (index == 6)return Color(TEXT_YELLOW);
}

Vector2 Renderer::SpriteIndexToPosition(const int textureIndex, const int index)
{
	int x = (index % (spritesheets[textureIndex].spritesheet.width / spritesheets[textureIndex].spriteSize));
	int y = (index / (spritesheets[textureIndex].spritesheet.width / spritesheets[textureIndex].spriteSize));
	return { (float)x,(float)y };
}

void Renderer::DrawSprite(int textureIndex, Vector2 texturePosition, Vector2 position, Color color)
{
	Rectangle source = GetSpriteRectangle(textureIndex, texturePosition);
	Rectangle dest = {	position.x*SCALE_FACTOR,
						position.y*SCALE_FACTOR,
						spritesheets[textureIndex].spriteSize*SCALE_FACTOR,
						spritesheets[textureIndex].spriteSize*SCALE_FACTOR};
	Vector2 origin = {	(spritesheets[textureIndex].spriteSize / 2)*SCALE_FACTOR , (spritesheets[textureIndex].spriteSize / 2)*SCALE_FACTOR };
	DrawTexturePro(spritesheets[textureIndex].spritesheet, source, dest, origin, 0, color);
}

void Renderer::DrawSprite(int textureIndex, Vector2 texturePosition, Vector2 position, int color)
{
	Color color_ = GetCustomColor(color);
	DrawSprite(textureIndex, texturePosition, position, color_);
}

void Renderer::DrawText(const char* text, const int length, Vector2 position, Color color)
{
	for (int i = 0; i < length; i++)
	{
		int character = (int)text[i];
		int asciiCode = character;
		if ((asciiCode > 64 && asciiCode < 91) || (asciiCode > 96 && asciiCode < 123))
		{
			if (asciiCode < 91)
			{
				DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 65), { position.x + 8 * i+4, position.y+4 }, color);
			}
			else if (asciiCode > 96)
			{
				DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 97), { position.x + 8 * i+4, position.y+4 }, color);
			}
		}
		else if (asciiCode > 47 && asciiCode < 58)
			DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 48 + 31), { position.x + 8 * i + 4, position.y + 4 }, color);
		else if (asciiCode == 33)
			DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 33 + 26), { position.x + 8 * i + 4, position.y + 4 }, color);
		else if (asciiCode == 126)
			DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 126 + 27), { position.x + 8 * i + 4, position.y + 4 }, color);
		else if (asciiCode == 47)
			DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 47 + 41), { position.x + 8 * i + 4, position.y + 4 }, color);
		else if (asciiCode == 45)
			DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 45 + 42), { position.x + 8 * i + 4, position.y + 4 }, color);
		else if (asciiCode == 39)
			DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 39 + 43), { position.x + 8 * i + 4, position.y + 4 }, color);
		else if (asciiCode == 46)
			DrawSprite(2, SpriteIndexToPosition(2, asciiCode - 46 + 51), { position.x + 8 * i + 4, position.y + 4 }, color);
		else if (asciiCode == 61)																								//NAMCO
		{
			DrawSprite(2, SpriteIndexToPosition(2, 44), { position.x + 8 * i + 4, position.y + 4 }, color);
			i++;
			DrawSprite(2, SpriteIndexToPosition(2, 45), { position.x + 8 * i + 4, position.y + 4 }, color);
			i++;
			DrawSprite(2, SpriteIndexToPosition(2, 46), { position.x + 8 * i + 4, position.y + 4 }, color);
			i++;
			DrawSprite(2, SpriteIndexToPosition(2, 47), { position.x + 8 * i + 4, position.y + 4 }, color);
			i++;
			DrawSprite(2, SpriteIndexToPosition(2, 48), { position.x + 8 * i + 4, position.y + 4 }, color);
			i++;
			DrawSprite(2, SpriteIndexToPosition(2, 49), { position.x + 8 * i + 4, position.y + 4 }, color);
			i++;
			DrawSprite(2, SpriteIndexToPosition(2, 50), { position.x + 8 * i + 4, position.y + 4 }, color);
		}
		else if (asciiCode == 58)
		{
			DrawSprite(2, SpriteIndexToPosition(2, 28), { position.x + 8 * i + 4, position.y + 4 }, color);
			i++;
			DrawSprite(2, SpriteIndexToPosition(2, 29), { position.x + 8 * i + 4, position.y + 4 }, color);
			i++;
			DrawSprite(2, SpriteIndexToPosition(2, 30), { position.x + 8 * i + 4, position.y + 4 }, color);
		}
	}
}

void Renderer::DrawText(const char* text, const int length, Vector2 position, int color)
{
	Color color_ = GetCustomColor(color);
	DrawText(text, length, position, color_);
}

void Renderer::DrawNumber(int number, Vector2 position, Color color)
{
	string num = to_string(number);
	DrawText(num.c_str(), num.size(), position, color);
}

void Renderer::DrawNumber(int number, Vector2 position, int color)
{
	Color color_ = GetCustomColor(color);
	DrawNumber(number, position, color_);
}

 Vector2 Renderer::AnchorNumberOnRight(int number, Vector2 initialPos)
{
	 int length = 0;
	 while (number / 10 > 0)
	 {
		 length++;
		 number /= 10;
	 }
	 return { initialPos.x-8*length,initialPos.y};
}

 Animator::Animator()
 {
	 currentSprite = 0;
	 timer = 0;
 }

 void Animator::Animate(Vector2 pos_, int animIndex, float sp_, bool loop_)
 {
	 timer += GetFrameTime();
	 if (timer >= sp_)
	 {
		 timer = 0;
		 currentSprite++;
	 }

	 if (currentSprite >= animations[animIndex].size)
	 {
		 if (loop_)
			 currentSprite = 0;
		 else
			 currentSprite = animations[animIndex].size-1;
	 }
	 if(animations[animIndex].sprites[currentSprite] >= 0)
		Renderer::Instance().DrawSprite(animations[animIndex].spritesheetIndex, Renderer::Instance().SpriteIndexToPosition(animations[animIndex].spritesheetIndex,animations[animIndex].sprites[currentSprite]), pos_, WHITE);
 }

 Animator::~Animator()
 {
 }
