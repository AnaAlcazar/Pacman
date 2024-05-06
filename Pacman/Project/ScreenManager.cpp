#include "ScreenManager.hpp"

Screen::Screen(const int layout_[36][28])
{
	for (int y = 0; y < 36; y++)
	{
		for (int x = 0; x < 28; x++)
		{
			layout[y][x] = layout_[y][x];
		}
	}
}

int Screen::GetValue(Vector2 tile)
{
    return layout[(int)tile.y][(int)tile.x];
}

void Screen::RenderLayout(const Color color_)
{
	for (int y = 0; y < 36; y++)
	{
		for (int x = 0; x < 28; x++)
		{
            if (layout[y][x] == -1)continue;
			Renderer::Instance().DrawSprite(1, Renderer::Instance().SpriteIndexToPosition(1, layout[y][x]), { (float)(x*8)+4, (float)(y*8)+4 }, color_);
		}
	}
}

Screen::~Screen()
{
}

ScreenManager::ScreenManager()
{
    int layoutEmpty[36][28] = {
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                                {36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36},
                            };
	int layoutMap[36][28] = {
							{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                            {0, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 9, 8, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 1},
                            {12, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 31, 10, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33},
                            {12, 36, 4, 30, 30, 5, 36, 4, 30, 30, 30, 5, 36, 31, 10, 36, 4, 30, 30, 30, 5, 36, 4, 30, 30, 5, 36, 33},
                            {12, 36, 31, -1, -1, 10, 36, 31, -1, -1, -1, 10, 36, 31, 10, 36, 31, -1, -1, -1, 10, 36, 31, -1, -1, 10, 36, 33},
                            {12, 36, 24, 11, 11, 25, 36, 24, 11, 11, 11, 25, 36, 24, 25, 36, 24, 11, 11, 11, 25, 36, 24, 11, 11, 25, 36, 33},
                            {12, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33},
                            {12, 36, 4, 30, 30, 5, 36, 4, 5, 36, 4, 30, 30, 30, 30, 30, 30, 5, 36, 4, 5, 36, 4, 30, 30, 5, 36, 33},
                            {12, 36, 24, 11, 11, 25, 36, 31, 10, 36, 24, 11, 11, 3, 2, 11, 11, 25, 36, 31, 10, 36, 24, 11, 11, 25, 36, 33},
                            {12, 36, 36, 36, 36, 36, 36, 31, 10, 36, 36, 36, 36, 31, 10, 36, 36, 36, 36, 31, 10, 36, 36, 36, 36, 36, 36, 33},
                            {20, 32, 32, 32, 32, 5, 36, 31, 22, 30, 30, 5, 36, 31, 10, 36, 4, 30, 30, 23, 10, 36, 4, 32, 32, 32, 32, 21},
                            {-1, -1, -1, -1, -1, 12, 36, 31, 2, 11, 11, 25, 36, 24, 25, 36, 24, 11, 11, 3, 10, 36, 33, -1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1, 12, 36, 31, 10, 36, 36, 36, 37, 36, 36, 37, 36, 36, 36, 31, 10, 36, 33, -1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1, 12, 36, 31, 10, 36, 14, 32, 17, 36, 36, 16, 32, 15, 36, 31, 10, 36, 33, -1, -1, -1, -1, -1},
                            {13, 13, 13, 13, 13, 25, 36, 24, 25, 36, 33, 36, 36, 36, 36, 36, 36, 12, 36, 24, 25, 36, 24, 13, 13, 13, 13, 13},
                            {38, 38, 38, 36, 36, 36, 36, 36, 36, 36, 33, 36, 36, 36, 36, 36, 36, 12, 36, 36, 36, 36, 36, 36, 36, 38, 38, 38},
                            {32, 32, 32, 32, 32, 5, 36, 4, 5, 36, 33, 36, 36, 36, 36, 36, 36, 12, 36, 4, 5, 36, 4, 32, 32, 32, 32, 32},
                            {-1, -1, -1, -1, -1, 12, 36, 31, 10, 36, 34, 13, 13, 13, 13, 13, 13, 35, 36, 31, 10, 36, 33, -1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1, 12, 36, 31, 10, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 31, 10, 36, 33, -1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1, 12, 36, 31, 10, 36, 4, 30, 30, 30, 30, 30, 30, 5, 36, 31, 10, 36, 33, -1, -1, -1, -1, -1},
                            {0, 13, 13, 13, 13, 25, 36, 24, 25, 36, 24, 11, 11, 3, 2, 11, 11, 25, 36, 24, 25, 36, 24, 13, 13, 13, 13, 1},
                            {12, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 31, 10, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33},
                            {12, 36, 4, 30, 30, 5, 36, 4, 30, 30, 30, 5, 36, 31, 10, 36, 4, 30, 30, 30, 5, 36, 4, 30, 30, 5, 36, 33},
                            {12, 36, 24, 11, 3, 10, 36, 24, 11, 11, 11, 25, 36, 24, 25, 36, 24, 11, 11, 11, 25, 36, 31, 2, 11, 25, 36, 33},
                            {12, 36, 36, 36, 31, 10, 36, 36, 36, 36, 36, 36, 37, 36, 36, 37, 36, 36, 36, 36, 36, 36, 31, 10, 36, 36, 36, 33},
                            {26, 30, 5, 36, 31, 10, 36, 4, 5, 36, 4, 30, 30, 30, 30, 30, 30, 5, 36, 4, 5, 36, 31, 10, 36, 4, 30, 27},
                            {6, 11, 25, 36, 24, 25, 36, 31, 10, 36, 24, 11, 11, 3, 2, 11, 11, 25, 36, 31, 10, 36, 24, 25, 36, 24, 11, 7},
                            {12, 36, 36, 36, 36, 36, 36, 31, 10, 36, 36, 36, 36, 31, 10, 36, 36, 36, 36, 31, 10, 36, 36, 36, 36, 36, 36, 33},
                            {12, 36, 4, 30, 30, 30, 30, 23, 22, 30, 30, 5, 36, 31, 10, 36, 4, 30, 30, 23, 22, 30, 30, 30, 30, 5, 36, 33},
                            {12, 36, 24, 11, 11, 11, 11, 11, 11, 11, 11, 25, 36, 24, 25, 36, 24, 11, 11, 11, 11, 11, 11, 11, 11, 25, 36, 33},
                            {12, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 33},
                            {20, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 21},
                            {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                            {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
						};
    Screen Empty = Screen(layoutEmpty);
    Screen Map = Screen(layoutMap);
    Screens.push_back(Empty);
    Screens.push_back(Map);
}

ScreenManager::~ScreenManager()
{
    Screens.clear();
}

void ScreenManager::Render(const int index, const Color color_)
{
    Screens[index].RenderLayout(color_);
}

void ScreenManager::Render(const int index, const int color_)
{
    Color newColor = Renderer::Instance().GetCustomColor(color_);
	Render(index, newColor);
}

bool ScreenManager::IsTangible(Vector2 tile)
{
    if (Screens[1].GetValue(tile) == 36)return true;
    else if (Screens[1].GetValue(tile) == 37)return true;
    else if (Screens[1].GetValue(tile) == 38)return true;
    else return false;
}
