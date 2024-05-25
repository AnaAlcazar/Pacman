#pragma once
#include "Renderer.hpp"
#include <vector>
using namespace std;

class Screen
{
private:
	int layout[36][28];
public:
	Screen(const int layout_[36][28]);
	int GetValue(Vector2 tile);
	void RenderLayout(const Color color_);
	~Screen();
};

class ScreenManager
{
private:
	vector <Screen> Screens;
	ScreenManager();
	~ScreenManager();
public:
	static ScreenManager& Instance()
	{
		static ScreenManager instance;
		return instance;
	}
	void Render(const int index, const Color color_);
	void Render(const int index, const int color_);
	bool OnTunnel(Vector2 tile, float dir);
	bool IsTangible(Vector2 tile);
};