#include "Renderer.hpp"
#include "CustomColors.hpp"
#include <iostream>

Renderer::Renderer()
{
	SpriteSheet general{ LoadTexture("assets/sprites/General.png"), 16};
	SpriteSheet map{ LoadTexture("assets/sprites/Map.png"), 8 };
	SpriteSheet text{ LoadTexture("assets/sprites/Text.png"), 8 };
	spritesheets.push_back(general);
	spritesheets.push_back(map);
	spritesheets.push_back(text);
}

Rectangle Renderer::GetSpriteRectangle(int textureIndex, Vector2 texturePosition)
{

	Rectangle sprite = {	spritesheets[textureIndex].spriteSize * texturePosition.x,
							spritesheets[textureIndex].spriteSize * texturePosition.y,
							spritesheets[textureIndex].spriteSize, spritesheets[textureIndex].spriteSize };
	return sprite;
}

Color Renderer::GetCustomColor(int index)
{
	if(index == 0)return Color(MAP_BLUE);
	else if (index == 1)return Color(TEXT_BLUE);
	else if (index == 2)return Color(TEXT_OCHER);
	else if (index == 3)return Color(TEXT_ORANGE);
	else if (index == 4)return Color(TEXT_PINK);
	else if (index == 4)return Color(TEXT_RED);
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
	Rectangle dest = {	position.x,
						position.y,
						spritesheets[textureIndex].spriteSize,
						spritesheets[textureIndex].spriteSize};
	Vector2 origin = {	spritesheets[textureIndex].spriteSize / 2 , spritesheets[textureIndex].spriteSize / 2 };
	DrawTexturePro(spritesheets[textureIndex].spritesheet, source, dest, origin, 0, color);
}

void Renderer::DrawSprite(int textureIndex, Vector2 texturePosition, Vector2 position, int color)
{
	Color color_ = GetCustomColor(color);
	DrawSprite(textureIndex, texturePosition, position, color_);
}

void Renderer::DrawText(char* text, int length, Vector2 position, Color color)
{
	for (int i = 0; i < length; i++)
	{
		int character = (int)text[i];
		int asciiCode = character;
		if (asciiCode > 39 && asciiCode != 21 && asciiCode != 47 && asciiCode != 45 && asciiCode != 22 && asciiCode != 46)
		{
			if (asciiCode < 0) asciiCode = character - 61;
			if (asciiCode < 0) asciiCode = character - 41;
		}
	}
}

void Renderer::DrawText(char* text, int length, Vector2 position, int color)
{
	Color color_ = GetCustomColor(color);
	DrawText(text, length, position, color_);
}
