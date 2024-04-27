#include "Renderer.hpp"
#include "CustomColors.hpp"

Renderer::Renderer()
{
	SpriteSheet general{ LoadTexture("../assets/sprites/General.png"), 16};
	SpriteSheet map{ LoadTexture("../assets/sprites/Map.png"), 16 };
	SpriteSheet text{ LoadTexture("../assets/sprites/Text.png"), 16 };
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
	Vector2 position = {(float) (index%(spritesheets[textureIndex].spritesheet.width/ spritesheets[textureIndex].spriteSize)* spritesheets[textureIndex].spriteSize),
	(float)(index / (spritesheets[textureIndex].spritesheet.width / spritesheets[textureIndex].spriteSize) * spritesheets[textureIndex].spriteSize) };
	return position;
}

void Renderer::DrawSprite(int textureIndex, Vector2 texturePosition, Vector2 position, Color color)
{
	Rectangle source = GetSpriteRectangle(textureIndex, texturePosition);
	Rectangle dest = {	spritesheets[textureIndex].spriteSize * position.x,
						spritesheets[textureIndex].spriteSize * position.y,
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